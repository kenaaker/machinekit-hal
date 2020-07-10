# see http://www.cmcrossroads.com/ask-mr-make/6535-tracing-rule-execution-in-gnu-make
# Delete the default suffix rules
.SUFFIXES:
.PHONY: all header_includes clean install python pythonclean

ECHO=echo

BASEPWD := $(shell pwd)
export BASEPWD

PYTHONPATH:=$(HAL_HOME)/lib/python:$(PYTHONPATH)
export PYTHONPATH

# For each file to be copied to ../include, its location in the source tree
# is listed here.  Note that due to $(INCLUDES), defined above, the include
# files in the source tree are the ones used when building machinekit.  The copy
# in ../include is used when building external components of machinekit.
HEADERS_HAL_LIB :=
HEADERS_HAL_LIB += hal/lib/hal_accessor.h
HEADERS_HAL_LIB += hal/lib/hal_accessor_macros.h
HEADERS_HAL_LIB += hal/lib/config_module.h
HEADERS_HAL_LIB += hal/lib/hal_group.h
HEADERS_HAL_LIB += hal/lib/hal.h
HEADERS_HAL_LIB += hal/lib/hal_iring.h
HEADERS_HAL_LIB += hal/lib/hal_internal.h
HEADERS_HAL_LIB += hal/lib/hal_iter.h
HEADERS_HAL_LIB += hal/lib/hal_list.h
HEADERS_HAL_LIB += hal/lib/hal_logging.h
HEADERS_HAL_LIB += hal/lib/hal_object.h
HEADERS_HAL_LIB += hal/lib/hal_object_selectors.h
HEADERS_HAL_LIB += hal/lib/hal_priv.h
HEADERS_HAL_LIB += hal/lib/hal_rcomp.h
HEADERS_HAL_LIB += hal/lib/hal_ring.h
HEADERS_HAL_LIB += hal/lib/hal_types.h
HEADERS_HAL_LIB += hal/lib/vtable.h
HEADERS_HAL_LIB += hal/lib/hal_parport.h

HEADERS_HAL_DRIVERS :=
HEADERS_HAL_DRIVERS += hal/drivers/hal_spi.h

HEADERS_HAL_INI :=
HEADERS_HAL_INI += inifile/mk-inifile.h
HEADERS_HAL_INI += inifile/mk-inifile.hh

HEADERS_HAL_RTAPI :=
HEADERS_HAL_RTAPI += rtapi/multiframe_flag.h
HEADERS_HAL_RTAPI += rtapi/rtapi.h
HEADERS_HAL_RTAPI += rtapi/rtapi_app.h
HEADERS_HAL_RTAPI += rtapi/rtapi_atomics.h
HEADERS_HAL_RTAPI += rtapi/rtapi_mutex.h
HEADERS_HAL_RTAPI += rtapi/rtapi_bitops.h
HEADERS_HAL_RTAPI += rtapi/rtapi_byteorder.h
HEADERS_HAL_RTAPI += rtapi/rtapi_export.h
HEADERS_HAL_RTAPI += rtapi/rtapi_compat.h
HEADERS_HAL_RTAPI += rtapi/rtapi_hexdump.h
HEADERS_HAL_RTAPI += rtapi/rtapi_int.h
HEADERS_HAL_RTAPI += rtapi/rtapi_limits.h
HEADERS_HAL_RTAPI += rtapi/rtapi_math.h
HEADERS_HAL_RTAPI += rtapi/rtapi_math64.h
HEADERS_HAL_RTAPI += rtapi/rtapi_stdint.h
HEADERS_HAL_RTAPI += rtapi/rtapi_bool.h
HEADERS_HAL_RTAPI += rtapi/rtapi_common.h
HEADERS_HAL_RTAPI += rtapi/rtapi_exception.h
HEADERS_HAL_RTAPI += rtapi/rtapi_global.h
HEADERS_HAL_RTAPI += rtapi/rtapi_shmkeys.h
HEADERS_HAL_RTAPI += rtapi/rtapi_errno.h
HEADERS_HAL_RTAPI += rtapi/rtapi_string.h
HEADERS_HAL_RTAPI += rtapi/rtapi_pci.h
HEADERS_HAL_RTAPI += rtapi/rtapi_heap.h
HEADERS_HAL_RTAPI += rtapi/rtapi_heap_private.h
HEADERS_HAL_RTAPI += rtapi/ring.h
HEADERS_HAL_RTAPI += rtapi/triple-buffer.h
HEADERS_HAL_RTAPI += rtapi/multiframe.h
HEADERS_HAL_RTAPI += rtapi/rtapi_mbarrier.h
HEADERS_HAL_RTAPI += rtapi/rtapi_io.h

HEADERS_HAL_SHMDRV :=
HEADERS_HAL_SHMDRV += rtapi/shmdrv/shmdrv.h

HEADERS_HAL_RTAPI_FLAVOR :=
HEADERS_HAL_RTAPI_FLAVOR += rtapi/flavor/rtapi_flavor.h
HEADERS_HAL_RTAPI_FLAVOR += rtapi/flavor/xenomai2.h
HEADERS_HAL_RTAPI_FLAVOR += rtapi/flavor/rt-preempt.h
HEADERS_HAL_RTAPI_FLAVOR += rtapi/flavor/ulapi.h

HEADER_HAL_LIB_INCLUDES := $(patsubst %,../include/%,$(foreach h,$(HEADERS_HAL_LIB),$(notdir $h)))

HEADER_HAL_DRIVER_INCLUDES := $(patsubst %,../include/%,$(foreach h,$(HEADERS_HAL_DRIVERS),$(notdir $h)))

HEADER_HAL_INI_INCLUDES := $(patsubst %,../include/%,$(foreach h,$(HEADERS_HAL_INI),$(notdir $h)))

HEADER_HAL_SHMDRV_INCLUDES := $(patsubst %,../include/%,$(foreach h,$(HEADERS_HAL_SHMDRV),$(notdir $h)))

HEADER_HAL_RTAPI_INCLUDES := $(patsubst %,../include/%,$(foreach h,$(HEADERS_HAL_RTAPI),$(notdir $h)))

HEADER_HAL_RTAPI_FLAVOR_INCLUDES := $(patsubst %,../include/%,$(foreach h,$(HEADERS_HAL_RTAPI_FLAVOR),$(notdir $h)))

HEADER_INCLUDES :=
HEADER_INCLUDES += $(HEADER_HAL_LIB_INCLUDES)
HEADER_INCLUDES += $(HEADER_HAL_DRIVER_INCLUDES)
HEADER_INCLUDES += $(HEADER_HAL_INI_INCLUDES)
HEADER_INCLUDES += $(HEADER_HAL_SHMDRV_INCLUDES)
HEADER_INCLUDES += $(HEADER_HAL_RTAPI_INCLUDES) 
HEADER_INCLUDES += $(HEADER_HAL_RTAPI_FLAVOR_INCLUDES)

SUBDIRS := 
SUBDIRS += machinetalk
#SUBDIRS += machinetalk/support
#SUBDIRS += machinetalk/messagebus
#SUBDIRS += machinetalk/msgcomponents
#SUBDIRS += machinetalk/lib
#SUBDIRS += machinetalk/config-service
#SUBDIRS += machinetalk/haltalk
#SUBDIRS += machinetalk/mkwrapper
#SUBDIRS += machinetalk/mklauncher
#SUBDIRS += machinetalk/videoserver
#SUBDIRS += rtapi/rtapi_math
SUBDIRS += inifile
SUBDIRS += rtapi
#SUBDIRS += rtapi/examples/timer
#SUBDIRS += rtapi/examples/shmem
#SUBDIRS += rtapi/examples
#SUBDIRS += rtapi/shmdrv
#SUBDIRS += rtapi/userpci
SUBDIRS += hal
#SUBDIRS += hal/lib
#SUBDIRS += hal/i_components
#SUBDIRS += hal/components
#SUBDIRS += hal/vtable-example
#SUBDIRS += hal/userfunct-example
#SUBDIRS += hal/cython
#SUBDIRS += hal/drivers
#SUBDIRS += hal/user_comps
#SUBDIRS += hal/user_icomps
#SUBDIRS += hal/user_comps/vismach
#SUBDIRS += hal/user_comps/vfs11_vfd
#SUBDIRS += hal/user_comps/vfdb_vfd
#SUBDIRS += hal/user_comps/mb2hal
#SUBDIRS += hal/user_comps/huanyang-vfd
#SUBDIRS += hal/user_comps/xhc-whb04b-6
#SUBDIRS += hal/classicladder
#SUBDIRS += hal/utils
#SUBDIRS += hal/support
#SUBDIRS += hal/drivers/hal_pru_generic
#SUBDIRS += hal/simdrivers
#SUBDIRS += hal/accessor
#SUBDIRS += emc/ini
#SUBDIRS += emc

# $(warning $$SUBDIRS=$(SUBDIRS))

# default target:  put before everything else
all: header_includes subdirs

header_includes: $(HEADER_INCLUDES)

subdirs: | $(SUBDIRS)

$(SUBDIRS)::
	$(MAKE) --print-directory -C $@

../include/%.h: hal/lib/%.h
	$(ECHO) Copying header file $@
	-cp $^ $@

../include/%.hh: hal/lib/%.hh
	$(ECHO) Copying header file $@
	-cp $^ $@
	
../include/%.h: hal/drivers/%.h | $(dir $@)
	$(ECHO) Copying header file $@
	-cp $^ $@
	
../include/%.hh: hal/drivers/%.hh | $(dir $@)
	$(ECHO) Copying header file $@
	-cp $^ $@

../include/%.h: rtapi/shmdrv/%.h | $(dir $@)
	$(ECHO) Copying header file $@
	-cp $^ $@
	
../include/%.hh: rtapi/shmdrv/%.hh | $(dir $@)
	$(ECHO) Copying header file $@
	-cp $^ $@
	
../include/%.h: inifile/%.h | $(dir $@)
	$(ECHO) Copying header file $@
	-cp $^ $@
	
../include/%.hh: inifile/%.hh | $(dir $@)
	$(ECHO) Copying header file $@
	-cp $^ $@

../include/%.h: rtapi/%.h | $(dir $@)
	$(ECHO) Copying header file $@
	-cp $^ $@
	
../include/%.hh: rtapi/%.hh | $(dir $@)
	$(ECHO) Copying header file $@
	-cp $^ $@
	
../include/%.h: rtapi/flavor/%.h | $(dir $@)
	$(ECHO) Copying header file $@
	-cp $^ $@
	
../include/%.hh: rtapi/flavor/%.hh | $(dir $@)
	$(ECHO) Copying header file $@
	-cp $^ $@
	

OBJDIR := objects/modules
RTLIBDIR := ../rtlib/modules

#############################################################################################

INCLUDE_PREFIX = .

# Each item in INCLUDES is transformed into a -I directive later on
# The top directory is always included
INCLUDES := .
INCLUDES += include
INCLUDES += ../include

#$$(info $(call c_comp_build_rules,hal/components/encoderv2.o))


ifeq ($(BUILD_PYTHON),yes)
: EXTRAFLAGS += -fPIC -fno-strict-aliasing
USERSRCS += $(PYSRCS)
endif

# Find the list of object files for each type of source file
CUSERSRCS := $(filter %.c,$(USERSRCS))
CXXUSERSRCS := $(filter %.cc,$(USERSRCS))
CUSEROBJS = $(call TOOBJS,$(CUSERSRCS))
CXXUSEROBJS += $(call TOOBJS,$(CXXUSERSRCS))

# Find the list of build-arch object files for C sources
CUSERSRCS_BUILD := $(filter %.c,$(USERSRCS_BUILD))
CUSEROBJS_BUILD := $(call TOOBJS,$(CUSERSRCS_BUILD),_build)

ifdef TARGET_PLATFORM_BEAGLEBONE
-include $(wildcard $(READ_PRU_DEPS))
endif


# Each directory in $(INCLUDES) is passed as a -I directory when compiling.
ifeq ($(BUILD_PYTHON),yes)
INCLUDE += $(PYTHON_CPPFLAGS)
endif

# Compilation options.
OPT :=  -O2
DEBUG := -g -Wall -funwind-tables
INCS := $(patsubst %,-I%, $(INCLUDES))

CFLAGS := $(INCS) -DULAPI -std=gnu99 -fgnu89-inline

ARCH_CFLAGS := -Wunused

ifeq ($(RUN_IN_PLACE),yes)
LDFLAGS += -L$(LIB_DIR) -Wl,-rpath,$(LIB_DIR)
else
LDFLAGS += -Wl,-rpath-link,../lib
endif
LDFLAGS += -Wl,--no-as-needed

# Rules to make .o (object) files
$(CUSEROBJS): objects/%.o: %.c
	$(ECHO) Compiling_1 $<
	$(CC) $(CPPFLAGS) $(CFLAGS) $(EXTRAFLAGS) -MMD -MF "${@:.o=.d}" -MT "$@" -c $< -o $@

# Rules to make .o (object) files, build arch
$(CUSEROBJS_BUILD): objects/%_build.o: %.c
	$(ECHO) Compiling_2 $<
	$(CC_FOR_BUILD) $(CFLAGS) $(EXTRAFLAGS) -MMD -MF "${@:.o=.d}" -MT "$@" -c $< -o $@

$(CXXUSEROBJS): objects/%.o: %.cc
	$(ECHO) Compiling_3 ++ $<
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(EXTRAFLAGS) -MMD -MF "${@:.o=.d}" -MT "$@" -c $< -o $@
	
Makefile: config.h

INFILES :=
INFILES += ../scripts/realtime

INFILES += ../scripts/gen-rtapi.ini.sh
INFILES += ../scripts/halrun
INFILES += ../scripts/rip-environment

# These rules clean things up.
clean: 
	rm -rf objects
	rm -rf ../rtlib ../libexec
	rm -f ../etc/machinekit/*.ini
	rm -f ../etc/machinekit/*.conf
	rm -f $(COPY_CONFIGS)
	rm -f $(RTLIBDIR)/*.so
	rm -f hal/components/conv_*.comp
	rm -f hal/i_components/conv_*.icomp
	rm -f hal/components/*_bin.h   # generated by pasm for bb platform
	rm -rf ../libexec
	rm -f ../include/*.hh ../include/*.h

# So that nothing is built as root, this rule does not depend on the touched
# files (Note that files in depends/ might be rebuilt, and there's little that
# can be done about it)
fix_perms = test ! -f $(1) || (chown root $(1) && chmod 4750 $(1))

DIR=install -d -m 0755 -o root
FILE=install -m 0644 -o root
TREE=cp -dR
CONFIGFILE=install -m 0644
EXE=install -m 0755 -o root
SETUID=install -m 4755 -o root
GLOB=$(wildcard $(1))

install: install-kernel-indep
	$(ECHO) "Installed in $(DESTDIR) with prefix $(prefix)"

install-dirs:
	$(DIR)  $(DESTDIR)$(HAL_RTLIB_DIR) \
		$(DESTDIR)$(sysconfdir)/machinekit $(DESTDIR)$(bindir) \
		$(DESTDIR)$(includedir)/machinekit \
		$(DESTDIR)$(docdir) $(DESTDIR)$(ncfilesdir) \
		$(DESTDIR)$(HAL_LIBEXEC_DIR) \
		$(DESTDIR)$(mandir)/man1 \
		$(DESTDIR)$(mandir)/man3 \
		$(DESTDIR)$(mandir)/man9 \
		$(DESTDIR)$(sysconfdir)/rsyslog.d \
		$(DESTDIR)$(sysconfdir)/security/limits.d \
		$(DESTDIR)$(sysconfdir)/udev/rules.d \
		$(DESTDIR)$(sampleconfsdir) \
		$(DESTDIR)$(datadir)/machinekit \
		$(DESTDIR)$(datadir)/pkgconfig
	$(DIR)	$(DESTDIR)$(includedir)/machinekit/userpci

install-kernel-indep: install-dirs
	$(EXE) ../scripts/realtime $(DESTDIR)$(bindir)
	$(EXE) ../scripts/halrun $(DESTDIR)$(bindir)
	$(EXE) ../scripts/runtests $(DESTDIR)$(bindir)
	$(EXE) $(filter ../bin/%,$(TARGETS)) $(DESTDIR)$(bindir)
	$(FILE) $(filter ../lib/%.a ../lib/%.so.0,$(TARGETS)) $(DESTDIR)$(libdir)
	cp --no-dereference $(filter ../lib/%.so, $(TARGETS)) $(DESTDIR)$(libdir)
#	# don't run ldconfig under fakeroot (silence dpkg-build warning)
	-test -n "$$FAKED_MODE" || ldconfig $(DESTDIR)$(libdir)
	$(FILE) $(HEADERS) $(DESTDIR)$(includedir)/machinekit/
	$(FILE) $(USERPCI_HEADERS) $(DESTDIR)$(includedir)/machinekit/userpci
	$(FILE) ../share/pkgconfig/my-machinekit-hal.pc \
	    $(DESTDIR)$(datadir)/pkgconfig

	$(FILE) rtapi/rsyslogd-hal.conf $(DESTDIR)$(sysconfdir)/rsyslog.d/hal.conf
	$(FILE) rtapi/shmdrv/limits.d-machinekit.conf \
		$(DESTDIR)$(sysconfdir)/security/limits.d/machinekit.conf
	$(FILE) ../etc/machinekit/machinekit.ini $(DESTDIR)$(sysconfdir)/machinekit
	$(EXE) ../bin/mank $(DESTDIR)$(bindir)

install-kernel-indep: install-python

install-python: install-dirs
	$(DIR) $(DESTDIR)$(SITEPY)/machinekit
	$(DIR) $(DESTDIR)$(SITEPY)/machinekit/nosetests
	$(DIR) $(DESTDIR)$(SITEPY)/machinetalk
	$(DIR) $(DESTDIR)$(SITEPY)/fdm
	$(DIR) $(DESTDIR)$(SITEPY)/drivers
	$(EXE) ../bin/hal_input $(DESTDIR)$(bindir)
	$(EXE) ../bin/hal_gpio_mcp23017 $(DESTDIR)$(bindir)
	$(EXE) ../bin/hal_pwm_pca9685 $(DESTDIR)$(bindir)
	$(EXE) ../bin/hal_storage $(DESTDIR)$(bindir)
	$(EXE) ../bin/hal_temp_ads7828 $(DESTDIR)$(bindir)
	$(EXE) ../bin/hal_temp_bbb $(DESTDIR)$(bindir)
	$(EXE) ../bin/hal_temp_atlas $(DESTDIR)$(bindir)
	$(FILE) ../lib/python/*.py ../lib/python/*.so $(DESTDIR)$(SITEPY)
	$(FILE) ../lib/python/machinekit/*.py $(DESTDIR)$(SITEPY)/machinekit/
	$(FILE) ../lib/python/machinekit/nosetests/*.py $(DESTDIR)$(SITEPY)/machinekit/nosetests
	$(FILE) ../lib/python/machinekit/*.so $(DESTDIR)$(SITEPY)/machinekit/
	$(FILE) ../lib/python/drivers/*.py $(DESTDIR)$(SITEPY)/drivers
	$(EXE) ../bin/mkwrapper $(DESTDIR)$(bindir)
	$(EXE) ../bin/mklauncher $(DESTDIR)$(bindir)
	$(EXE) ../bin/configserver $(DESTDIR)$(bindir)
	$(EXE) ../bin/videoserver $(DESTDIR)$(bindir)

	$(EXE) ../libexec/inivar $(DESTDIR)$(HAL_LIBEXEC_DIR)
	$(EXE) ../libexec/rtapi_msgd $(DESTDIR)$(HAL_LIBEXEC_DIR)
	$(FILE) ../etc/machinekit/rtapi.ini $(DESTDIR)$(sysconfdir)/machinekit


CONF=../configs
COMMON=$(CONF)/common
CONFILES=$(addsuffix /$(1), $(filter-out $(COMMON) $(CONF),\
                                         ${shell find ${CONF} -type d -print}))

#################################################################################################################

EXTRA_CFLAGS += $(ARCH_CFLAGS)
EXTRA_CFLAGS += -D__MODULE__
EXTRA_CFLAGS += -DSEQUENTIAL_SUPPORT
EXTRA_CFLAGS += -DHAL_SUPPORT
EXTRA_CFLAGS += -DDYNAMIC_PLCSIZE
EXTRA_CFLAGS += -DRT_SUPPORT
EXTRA_CFLAGS += -DOLD_TIMERS_MONOS_SUPPORT
EXTRA_CFLAGS += -DMODBUS_IO_MASTER
EXTRA_CFLAGS += -I./hal/support/pru

#######################################################################################################

%_pb2.py: %.proto
	$(PROTOC) --python_out=. $<


# Define libexec dir first, since it contains tools needed to compute
# following definitions
HAL_LIBEXEC_DIR=/afs/aaker.org/home/kdaaker/src/CAM_stuff/machinekit/my-machinekit-hal/libexec
	
# Directories
prefix=/afs/aaker.org/home/kdaaker/src/CAM_stuff/machinekit/my-machinekit-hal
exec_prefix=${prefix}
	
HAL_HOME=/afs/aaker.org/home/kdaaker/src/CAM_stuff/machinekit/my-machinekit-hal
LIB_DIR=/afs/aaker.org/home/kdaaker/src/CAM_stuff/machinekit/my-machinekit-hal/lib
	
#used for install stuff
#but have them here as reference
#build system only uses HAL_RTLIB_DIR when creating rtapi.ini
HAL_BIN_DIR=/afs/aaker.org/home/kdaaker/src/CAM_stuff/machinekit/my-machinekit-hal/bin
HAL_HELP_DIR=/afs/aaker.org/home/kdaaker/src/CAM_stuff/machinekit/my-machinekit-hal/help
HAL_RTLIB_BASE_DIR=/afs/aaker.org/home/kdaaker/src/CAM_stuff/machinekit/my-machinekit-hal/rtlib
HAL_RTLIB_DIR=$(HAL_RTLIB_BASE_DIR)/modules
HAL_SYSTEM_CONFIG_DIR=${prefix}/etc/machinekit
HAL_NCFILES_DIR=@HAL_NCFILES_DIR@
REALTIME=/afs/aaker.org/home/kdaaker/src/CAM_stuff/machinekit/my-machinekit-hal/scripts/realtime
HAL_IMAGEDIR=/afs/aaker.org/home/kdaaker/src/CAM_stuff/machinekit/my-machinekit-hal
GIT_VERSION=unknown
GIT_CONFIG_SHA=00baf6dae
	
# Standard configure directories
# do we really need these?
bindir = ${exec_prefix}/bin
sbindir = ${exec_prefix}/sbin
libexecdir = ${exec_prefix}/libexec
datadir = ${datarootdir}
datarootdir = ${prefix}/share
sysconfdir = ${prefix}/etc
sharedstatedir = ${prefix}/com
localstatedir = ${prefix}/var
libdir = ${exec_prefix}/lib
infodir = ${datarootdir}/info
mandir = ${datarootdir}/man
includedir = ${prefix}/include
docdir = ${datarootdir}/doc/${PACKAGE_TARNAME}

# i18n variables:
	
package = machinekit
PACKAGE_TARNAME = machinekit
localedir = /usr/share/locale
LANGUAGES = 
	
# architecture-dependent optimizations
ARCH_CFLAGS=

# /Standard configure directories
RTOPT:=-O2 	$(ARCH_CFLAGS)
ULOPT:=-O2	$(ARCH_CFLAGS)
RUN_IN_PLACE = yes
	
EXTRA_CFLAGS := -I. -DRTAPI -D_GNU_SOURCE -D_FORTIFY_SOURCE=0
ULFLAGS = -D_GNU_SOURCE -DLOCALE_DIR=\"$(localedir)\" -DPACKAGE=\"$(package)\"
	
CC = $(CROSS_COMPILE)gcc
CC_FOR_BUILD = $(CROSS_COMPILE)gcc
OBJCOPY = $(CROSS_COMPILE)objcopy
LD = $(CROSS_COMPILE)ld
PKG_CONFIG = pkg-config
YAPPS2 = /usr/bin/yapps2
MANDB = /usr/bin/mandb
HIDRAW_H_USABLE = yes
	
HAS_SYS_IO = yes
SYS_IO_DEFINED = @SYS_IO_DEFINED@
	
BUILD_DRIVERS = yes
USE_PORTABLE_PARPORT_IO = no
TARGET_PLATFORM_PC = 
TARGET_PLATFORM_SOCFPGA = 
TARGET_PLATFORM_BEAGLEBONE = yes
TARGET_PLATFORM_CHIP = 
TARGET_PLATFORM_RASPBERRY = 
TARGET_PLATFORM_ZEDBOARD = 
TARGET_PLATFORM_H3 = 
	
HARDY_AMD64_WORKAROUND=@HARDY_AMD64_WORKAROUND@
PRECISE_MULTILIB_BUG=@PRECISE_MULTILIB_BUG@
	
# enable not-yet-ported NML parts
BUILD_NMLDEP=@BUILD_NMLDEP@
	
# protobuf messaging
PROTOC=/usr/bin/protoc
PROTOBUF_CFLAGS=-pthread
PROTOBUF_LIBS=-lprotobuf -pthread
USE_PROTOBUF=yes
PROTO2JS=none
	
## zeroMQ messaging
CZMQ_CFLAGS=-isystem /usr/include/mit-krb5 -I/usr/include/pgm-5.2 -I/usr/include/uuid
CZMQ_LIBS=-lczmq
USE_CZMQ=yes
	
# jansson JSON C library
JANSSON_CFLAGS=
JANSSON_LIBS=-ljansson
USE_JANSSON=yes
	
# libwebsockets C library
LWS_CFLAGS=
LWS_LIBS=-lwebsockets
USE_LWS=yes
	
# SSL library
SSL_CFLAGS=
SSL_LIBS=-lssl
USE_SSL=yes
	
# uriparser C library
URIPARSER_CFLAGS=
URIPARSER_LIBS=-luriparser
USE_URIPARSER=yes
	
# avahi-client library
AVAHI_CFLAGS=-D_REENTRANT
AVAHI_LIBS=-lavahi-common -lavahi-client
USE_AVAHI=yes
	
# uuid-dev C library
UUID_CFLAGS=-I/usr/include/uuid
UUID_LIBS=-luuid
USE_UUID=yes
	
LIBBACKTRACE = -lbacktrace
	
#libudev
LIBUDEV_CFLAGS=
LIBUDEV_LIBS=-ludev

# cgroup support
LIBCGROUP_CFLAGS=
LIBCGROUP_LIBS=-lcgroup

# deps for xemc
CFLAGS_X = 
XLIBS = -lX11 -lXaw -lXt
HAVE_XAW = yes
	
# ncurses support for keystick
KEYSTICKLIBS =  -lncurses
HAVE_NCURSES = yes
	
# readline support for halcmd
READLINE_LIBS =  -lreadline
	
# flags for glib
GLIB_CFLAGS = -I/usr/include/glib-2.0 -I/usr/lib/arm-linux-gnueabihf/glib-2.0/include
GLIB_LIBS = -lglib-2.0

CROSS_COMPILE := arm-linux-gnueabihf-

CFLAGS := "--sysroot=/home/kdaaker/nfs_mounts/beaglebone-cnc"
CXXFLAGS := "--sysroot=/home/kdaaker/nfs_mounts/beaglebone-cnc"

BASE_CXXFLAGS:= $(CXXFLAGS) $(patsubst %,-I%, $(INCLUDES)) $(ARCH_CFLAGS)

CXXFLAGS :=   $(BASE_CXXFLAGS) -DULAPI
RT_CXXFLAGS :=   $(BASE_CXXFLAGS)

# local flags for GTK include
HAVE_GTK = yes
GTK_CFLAGS = "--sysroot=/home/kdaaker/nfs_mounts/beaglebone-cnc" -pthread -I/usr/include/gtk-2.0 -I/usr/lib/arm-linux-gnueabihf/gtk-2.0/include -I/usr/include/gio-unix-2.0 -I/usr/include/cairo -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/pango-1.0 -I/usr/include/harfbuzz -I/usr/include/pango-1.0 -I/usr/include/fribidi -I/usr/include/glib-2.0 -I/usr/lib/arm-linux-gnueabihf/glib-2.0/include -I/usr/include/uuid -I/usr/include/freetype2 -I/usr/include/libpng16
GTK_LIBS = -lgtk-x11-2.0 -lgdk-x11-2.0 -lpangocairo-1.0 -latk-1.0 -lcairo -lgdk_pixbuf-2.0 -lgio-2.0 -lpangoft2-1.0 -lpango-1.0 -lgobject-2.0 -lglib-2.0 -lfontconfig -lfreetype
HAVE_GNOMEPRINT = 
	
AR = /usr/bin/ar
ARFLAGS = cr
CXX = $(CROSS_COMPILE)g++
RANLIB = ranlib
MSGFMT = /usr/bin/msgfmt
XGETTEXT = /usr/bin/xgettext
	
BUILD_DOCS = no
#BUILD_DOCS_PDF = @BUILD_DOCS_PDF@
#BUILD_DOCS_HTML = @BUILD_DOCS_HTML@
PYTHON = /usr/bin/python
A2X_LATEX_ENCODING = @A2X_LATEX_ENCODING@
	
HAVE_LIBMODBUS3   = yes
LIBMODBUS_LIBS    = -lmodbus
LIBMODBUS_CFLAGS  = -I/usr/include/modbus

HAVE_LIBUSB10   = yes
LIBUSB10_LIBS   = -lusb-1.0
LIBUSB10_CFLAGS = -I/usr/include/libusb-1.0
	
#### BEGIN CONFIG ####

# usually you need rtapi,
# so you probably don't want to change this
CONFIG_RTAPI=m

# rtapi examples
CONFIG_RTAPI_EXAMPLES_EXTINT=n
CONFIG_RTAPI_EXAMPLES_FIFO=n
CONFIG_RTAPI_EXAMPLES_SEM=n
CONFIG_RTAPI_EXAMPLES_SHMEM=n
CONFIG_RTAPI_EXAMPLES_TIMER=n

# emc motion module
CONFIG_MOTMOD=m

# HAL components
CONFIG_BLOCKS=m
CONFIG_BOSS_PLC=m
CONFIG_DEBOUNCE=m
CONFIG_ENCODER=m
CONFIG_COUNTER=m
CONFIG_ENCODER_RATIO=m
CONFIG_STEPGEN=m
CONFIG_LCD=m
CONFIG_MUX_GENERIC=m
CONFIG_MATRIX_KB=m
CONFIG_FREQGEN=m
CONFIG_PWMGEN=m
CONFIG_SIGGEN=m
CONFIG_AT_PID=m
CONFIG_PID=m
CONFIG_PEPPER=m
CONFIG_SUPPLY=m
CONFIG_CLASSICLADDER_RT=m
CONFIG_TIMEDELAY=m
CONFIG_SIM_ENCODER=m
CONFIG_WEIGHTED_SUM=m
CONFIG_WATCHDOG=m
CONFIG_MODMATH=m
CONFIG_STREAMER=m
CONFIG_SAMPLER=m
CONFIG_RINGLOAD=m

# HAL drivers
CONFIG_UPARPORT=m
CONFIG_HAL_PARPORT=m
CONFIG_PROBE_PARPORT=m
CONFIG_HAL_TIRO=m
CONFIG_HAL_EVOREG=m
CONFIG_HAL_MOTENC=m
CONFIG_HAL_SKELETON=m
CONFIG_HAL_GPIO=m
CONFIG_HM2_SOC_OL=m
CONFIG_HAL_SPI=m
CONFIG_HAL_SPEAKER=m
CONFIG_HAL_STG=m
CONFIG_HAL_VTI=m
CONFIG_HAL_AX521H=m
CONFIG_HAL_PPMC=m
CONFIG_PCI_8255=m
CONFIG_HOSTMOT2=m
CONFIG_OPTO_AC5=m
CONFIG_HAL_GM=m
CONFIG_HAL_CAN=m

# Python-related
BUILD_PYTHON=yes
PYTHON_CPPFLAGS=-I/usr/include/python2.7
PYTHON_LIBS=-lpython2.7
BOOST_PYTHON_LIB=@BOOST_PYTHON_LIB@
SITEPY=/usr/lib/python2.7/dist-packages
CYTHON=/usr/bin/cython

# Boost
BOOST_SERIALIZATION_LIB=@BOOST_SERIALIZATION_LIB@
BOOST_THREAD_LIB=@BOOST_THREAD_LIB@
# Later Boost versions need -lboost_system with -lboost_thread
BOOST_SYSTEM_LIB=@BOOST_SYSTEM_LIB@

#### END CONFIG ####
