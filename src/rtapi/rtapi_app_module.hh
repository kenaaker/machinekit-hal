/* Copyright (C) 2006-2008 Jeff Epler <jepler@unpythonic.net>
 * Copyright (C) 2012-2014 Michael Haberler <license@mah.priv.at>
 * Copyright (C) 2020 John Morris <john@dovetail-automata.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <limits.h> // PATH_MAX
#include <string>
#include "rtapi_compat.h" // get_elf_section()

// dlinfo()
#ifndef _GNU_SOURCE
#   define _GNU_SOURCE
#endif
#include <link.h>
#include <dlfcn.h>

class Module {
public:
    string name;
    void *handle;
    char *errmsg;

    int load(string module);
    string path();
    void clear_err();
    template <class T> T sym(const string &name);
    template <class T> T sym(const char *name);
    int elf_section(const char *section_name, void **dest);
    int close();
};

int Module::load(string module)
{
    char module_path[PATH_MAX];
    bool is_rpath;
    string dlpath;
    struct stat st;

    // For module given as a path (sans `.so`), use the path basename as the
    // module name
    if (module.find_last_of("/") != string::npos) {
        name = module.substr(module.find_last_of("/") + 1);
        is_rpath = false;  // `module` contains `/` chars
    } else {
        name = module;
        is_rpath = true;  // `module` contains no `/` chars
    }
    dlpath = module + ".so";
    handle = NULL;

    // First look in `$MK_MODULE_DIR` if `module` contains no `/` chars
    if (getenv("MK_MODULE_DIR") != NULL && is_rpath) {
        // If $MK_MODULE_DIR/module.so exists, load it (or fail)
        strncpy(module_path, getenv("MK_MODULE_DIR"), PATH_MAX);
        strncat(module_path, ("/" + dlpath).c_str(), PATH_MAX);
        if (stat(module_path, &st) == 0) {
            handle = dlopen(module_path, RTLD_GLOBAL|RTLD_NOW);
            if (!handle) {
                errmsg = dlerror();
                return -1;
            }
        }
    }
    // Otherwise load it with dlopen()'s logic (or fail)
    if (!handle)
        handle = dlopen(dlpath.c_str(), RTLD_GLOBAL |RTLD_NOW);
    if (!handle) {
        errmsg = dlerror();
        rtapi_print_msg(
            RTAPI_MSG_ERR, "load(%s): %s", module.c_str(), errmsg);
        return -1;
    }

    // Success
    errmsg = NULL;
    return 0;
}

string Module::path()
{
    char path[PATH_MAX];
    if (dlinfo(handle, RTLD_DI_ORIGIN, path) != 0) {
        rtapi_print_msg(RTAPI_MSG_ERR, "dlinfo(%s):  %s", path, dlerror());
        return NULL;
    }
    strncat(path, ("/" + name + ".so").c_str(), PATH_MAX);

    return string(path);
}

void Module::clear_err()
{
    dlerror();
    errmsg = NULL;
}

template <class T> T Module::sym(const char *sym_name)
{
    clear_err();
    T res = (T)(dlsym(handle, sym_name));
    if (!res)
        errmsg = dlerror();
    return res;
}

template <class T> T Module::sym(const string &sym_name)
{
    return sym<T>(sym_name.c_str());
}

int Module::close()
{
    return dlclose(handle);
}

int Module::elf_section(const char *section_name, void **dest)
{
    return get_elf_section(path().c_str(), section_name, dest);
}
