MKDIR = mkdir -p

ARCH ?= gcc-arm-none-eabi

ifneq (,$(findstring /cygdrive/,$(PATH)))
OS := WIN32
else
ifneq (,$(findstring WINDOWS,$(PATH)))
OS := WIN32
else
ifneq (,$(findstring Atmel Studio,$(PATH)))
OS := WIN32
else
UNAME := $(shell uname -s)

ifeq (Darwin,${UNAME})
OS = OSX
else
ifeq (Linux,${UNAME})
OS = LINUX
endif #LINUX
endif #Darwin

endif #Atmel Studio
endif #WINDOWS
endif #cygdrive

# ARM GCC ------

ifeq ($(ARCH), gcc-arm-none-eabi)

ifeq ("$(TOOLS_VERSION)", "6.2u1")

TOOLS_EASYPATH = gcc-arm-none-eabi-6.2u1

TOOLS_VERSION_FILENAME = 6-2017-q1-update

# Example:  https://developer.arm.com/-/media/Files/downloads/gnu-rm/6-2016q4/gcc-arm-none-eabi-6_2-2016q4-20161216-mac.tar.bz2?product=GNU%20ARM%20Embedded%20Toolchain,64-bit,,Mac%20OS%20X,6-2016-q4-major
#           https://developer.arm.com/-/media/Files/downloads/gnu-rm/6_1-2017q1/gcc-arm-none-eabi-6-2017-q1-update-win32.exe?product=GNU%20ARM%20Embedded%20Toolchain,32-bit,,Windows,6-2017-q1-update
# downloads as Mac: gcc-arm-none-eabi-6-2017-q1-update-mac.tar.bz2
#            Linux: gcc-arm-none-eabi-6-2017-q1-update-linux.tar.bz2
#          Windows: gcc-arm-none-eabi-6-2017-q1-update-win32.zip

# exapnds to Linux/Mac: gcc-arm-none-eabi-6-2017-q1-update
#              Windows: gcc-arm-none-eabi-6-2017-q1-update-win32

TOOLS_OSX_URL_PREFIX = https://developer.arm.com/-/media/Files/downloads/gnu-rm/6_1-2017q1/gcc-arm-none-eabi-6-2017-q1-update-mac.tar.bz2?product=GNU%20ARM%20Embedded%20Toolchain,64-bit,,Mac%20OS%20X,6-2017-q1-update
TOOLS_LINUX_URL_PREFIX = https://developer.arm.com/-/media/Files/downloads/gnu-rm/6_1-2017q1/gcc-arm-none-eabi-6-2017-q1-update-linux.tar.bz2?product=GNU%20ARM%20Embedded%20Toolchain,64-bit,,Linux,6-2017-q1-update
TOOLS_WIN32_URL_PREFIX = https://developer.arm.com/-/media/Files/downloads/gnu-rm/6_1-2017q1/gcc-arm-none-eabi-6-2017-q1-update-win32-zip.zip?product=GNU%20ARM%20Embedded%20Toolchain,ZIP,,Windows,6-2017-q1-update
TOOLS_URL_PREFIX = ${TOOLS_${OS}_URL_PREFIX}

TOOLS_OSX_ARCHIVE_FILENAME   = gcc-arm-none-eabi-${TOOLS_VERSION_FILENAME}-mac.tar.bz2
TOOLS_LINUX_ARCHIVE_FILENAME = gcc-arm-none-eabi-${TOOLS_VERSION_FILENAME}-linux.tar.bz2
TOOLS_WIN32_ARCHIVE_FILENAME = gcc-arm-none-eabi-${TOOLS_VERSION_FILENAME}-win32.zip

TOOLS_OSX_EXPANDED_DIRNAME   = gcc-arm-none-eabi-6-2017-q1-update
TOOLS_LINUX_EXPANDED_DIRNAME = gcc-arm-none-eabi-6-2017-q1-update
TOOLS_WIN32_EXPANDED_DIRNAME = gcc-arm-none-eabi-6-2017-q1-update-win32
TOOLS_EXPANDED_DIRNAME = ${TOOLS_${OS}_EXPANDED_DIRNAME}

TEST_COMMAND_BASE=arm-none-eabi-gcc

else ifeq ("$(TOOLS_VERSION)", "7u2")

TOOLS_EASYPATH = gcc-arm-none-eabi-7u2

TOOLS_VERSION_FILENAME = 7-2018-q2-update

# Example:
#  https://developer.arm.com/-/media/Files/downloads/gnu-rm/7-2018q2/gcc-arm-none-eabi-7-2018-q2-update-mac.tar.bz2?revision=982ef8a4-1815-4651-9c44-6144c9d8b34b?product=GNU%20Arm%20Embedded%20Toolchain,64-bit,,Mac%20OS%20X,7-2018-q2-update

# downloads as Mac: gcc-arm-none-eabi-7-2018-q2-update-mac.tar.bz2
#            Linux: gcc-arm-none-eabi-7-2018-q2-update-linux.tar.bz2
#          Windows: gcc-arm-none-eabi-7-2018-q2-update-win32.zip

# exapnds to Linux/Mac: gcc-arm-none-eabi-7-2018-q2-update
#              Windows: gcc-arm-none-eabi-7-2018-q2-update-win32

TOOLS_OSX_URL_PREFIX = https://developer.arm.com/-/media/Files/downloads/gnu-rm/7-2018q2/gcc-arm-none-eabi-7-2018-q2-update-mac.tar.bz2?revision=982ef8a4-1815-4651-9c44-6144c9d8b34b?product=GNU%20Arm%20Embedded%20Toolchain,64-bit,,Mac%20OS%20X,7-2018-q2-update
TOOLS_LINUX_URL_PREFIX = https://developer.arm.com/-/media/Files/downloads/gnu-rm/7-2018q2/gcc-arm-none-eabi-7-2018-q2-update-linux.tar.bz2?revision=bc2c96c0-14b5-4bb4-9f18-bceb4050fee7?product=GNU%20Arm%20Embedded%20Toolchain,64-bit,,Linux,7-2018-q2-update
TOOLS_WIN32_URL_PREFIX = https://developer.arm.com/-/media/Files/downloads/gnu-rm/7-2018q2/gcc-arm-none-eabi-7-2018-q2-update-win32.zip?revision=9b83e69c-e279-4d16-9401-990c836197b3?product=GNU%20Arm%20Embedded%20Toolchain,ZIP,,Windows,7-2018-q2-update
TOOLS_URL_PREFIX = ${TOOLS_${OS}_URL_PREFIX}

TOOLS_OSX_ARCHIVE_FILENAME   = gcc-arm-none-eabi-${TOOLS_VERSION_FILENAME}-mac.tar.bz2
TOOLS_LINUX_ARCHIVE_FILENAME = gcc-arm-none-eabi-${TOOLS_VERSION_FILENAME}-linux.tar.bz2
TOOLS_WIN32_ARCHIVE_FILENAME = gcc-arm-none-eabi-${TOOLS_VERSION_FILENAME}-win32.zip

TOOLS_OSX_EXPANDED_DIRNAME   = gcc-arm-none-eabi-${TOOLS_VERSION_FILENAME}
TOOLS_LINUX_EXPANDED_DIRNAME = gcc-arm-none-eabi-${TOOLS_VERSION_FILENAME}
TOOLS_WIN32_EXPANDED_DIRNAME = gcc-arm-none-eabi-${TOOLS_VERSION_FILENAME}-win32
TOOLS_EXPANDED_DIRNAME = ${TOOLS_${OS}_EXPANDED_DIRNAME}

TEST_COMMAND_BASE=arm-none-eabi-gcc

else

$(error The TOOLS_VERSION ($(TOOLS_VERSION)) requested is not a valid option. You project and Motate are mismatched. (?))

endif #$(TOOLS_VERSION)

endif #eq ($(ARCH), 'gcc-arm-none-eabi')

# AVR GCC ------

ifeq ($(ARCH), gcc-avr)

TOOLS_EASYPATH = gcc-avr

TOOLS_VERSION = 4.8.1-arduino3
TOOLS_EXPANDED_DIRNAME = avr

#http://arduino.cc/download.php?f=/tools/avr-gcc-4.8.1-arduino3-i386-apple-darwin11.tar.bz2
TOOLS_URL_PREFIX = http://arduino.cc/download.php?f=/tools/

TOOLS_OSX_ARCHIVE_FILENAME = avr-gcc-${TOOLS_VERSION}-i386-apple-darwin11.tar.bz2
TOOLS_LINUX_ARCHIVE_FILENAME = avr-${TOOLS_VERSION}-x86_64-pc-linux-gnu.tar.bz2
TOOLS_WIN32_ARCHIVE_FILENAME = avr-${TOOLS_VERSION}-i686-mingw32.zip

TEST_COMMAND_BASE=avr-gcc

endif #eq ($(ARCH), 'gcc-avr')


# all platforms from here on -----


EXPAND_COMMAND_OSX = tar xjf
TOOLS_SUBPATH_OSX = osx
TEST_COMMAND_OSX = ${TEST_COMMAND_BASE}
DOWNLOAD_TOOL_OSX = curl -L
DOWNLOAD_TOOL_SET_NAME_OSX = -o
# DOWNLOAD_TOOL_OSX = wget
# DOWNLOAD_TOOL_SET_NAME_OSX = -O

EXPAND_COMMAND_LINUX = tar xjf
TOOLS_SUBPATH_LINUX = linux
TEST_COMMAND_LINUX = ${TEST_COMMAND_BASE}
DOWNLOAD_TOOL_LINUX = wget
DOWNLOAD_TOOL_SET_NAME_LINUX = -O

EXPAND_COMMAND_WIN32 = 7za/7za x
TOOLS_SUBPATH_WIN32 = win32
TEST_COMMAND_WIN32 = ${TEST_COMMAND_BASE}.exe
DOWNLOAD_TOOL_WIN32 = curl -L
DOWNLOAD_TOOL_SET_NAME_WIN32 = -o

EXPAND_COMMAND = ${EXPAND_COMMAND_${OS}}
TOOLS_SUBPATH = ${TOOLS_SUBPATH_${OS}}
TEST_COMMAND = ${TEST_COMMAND_${OS}}
DOWNLOAD_TOOL = ${DOWNLOAD_TOOL_${OS}}
DOWNLOAD_TOOL_SET_NAME = ${DOWNLOAD_TOOL_SET_NAME_${OS}}
# NOTE: We set the PATH in the Motate.mk makefile that calls this!
# If it's missing stuff, then you're path is wrong!
#$(info PATH:$(PATH))

# Note the | -- order-only means we don't care about the modification date
TOOLS_FULL_EASYPATH_IF_NEEDED = | $(TOOLS_SUBPATH)/$(TOOLS_EASYPATH)

all: TOOLS_INSTALLED

.PHONY:
TOOLS_INSTALLED: ${TOOLS_FULL_EASYPATH_IF_NEEDED}


ifneq ($(OS), WIN32)

.ONESHELL:
$(TOOLS_SUBPATH)/$(TOOLS_EASYPATH): $(TOOLS_SUBPATH)/${TOOLS_EXPANDED_DIRNAME}
	cd $(TOOLS_SUBPATH) && \
	ln -s "${TOOLS_EXPANDED_DIRNAME}" "${TOOLS_EASYPATH}"

${TOOLS_SUBPATH}/${TOOLS_EXPANDED_DIRNAME}: ${TOOLS_SUBPATH}/${TOOLS_${OS}_ARCHIVE_FILENAME}
	cd $(TOOLS_SUBPATH) && \
	rm -f "${TOOLS_EASYPATH}" && \
	${EXPAND_COMMAND} ${TOOLS_${OS}_ARCHIVE_FILENAME} && \
	rm -f "${TOOLS_${OS}_ARCHIVE_FILENAME}"

else

## Additional test added to make sure we have curl.
## Otherwise, windows will NOT return non-zero for these commands and some wierd
## failure will happen later.

ifeq ($(shell command -v curl >/dev/null 2>&1 || echo "missing"), missing)
${info On windows git must be installed for the curl command. Please download and install from http://git-scm.com/downloads }
${info Current PATH: $(PATH) }
${error If you called this makefile directly (instead of from compiling Motate, you will get this error. Got back tot he Motate project you want to compile and `make tools`.) }
endif

# end additional curl test

.ONESHELL:
${TOOLS_SUBPATH}/$(TOOLS_EASYPATH): ${TOOLS_SUBPATH}/${TOOLS_${OS}_ARCHIVE_FILENAME} ${TOOLS_SUBPATH}/${TOOLS_${OS}_ARCHIVE_FILENAME}
	mkdir -p $(TOOLS_SUBPATH) && \
	cd $(TOOLS_SUBPATH) && \
	../${EXPAND_COMMAND} -o$(TOOLS_EASYPATH) "${TOOLS_${OS}_ARCHIVE_FILENAME}" && \
	rm -f "${TOOLS_${OS}_ARCHIVE_FILENAME}"

endif # if not windows/else


.INTERMEDIATE: ${TOOLS_SUBPATH}/${TOOLS_${OS}_ARCHIVE_FILENAME}
${TOOLS_SUBPATH}/${TOOLS_${OS}_ARCHIVE_FILENAME}:
	$(info The $(ARCH) tools need installed. Downloading ${TOOLS_SUBPATH}/${TOOLS_${OS}_ARCHIVE_FILENAME} and installing now.)
	mkdir -p $(TOOLS_SUBPATH) && \
	cd $(TOOLS_SUBPATH) && \
	${DOWNLOAD_TOOL} "${TOOLS_URL_PREFIX}${TOOLS_${OS}_ARCHIVE_FILENAME}" ${DOWNLOAD_TOOL_SET_NAME} "${TOOLS_${OS}_ARCHIVE_FILENAME}"

.PHONY: clean

clean:
	rm -rf ${TOOLS_SUBPATH}
