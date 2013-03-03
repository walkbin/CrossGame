LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := boost_date_time
LOCAL_MODULE_FILENAME := boost_date_time-gcc-mt-1_49
LOCAL_SRC_FILES := libs/$(TARGET_ARCH_ABI)/build/lib/libboost_date_time-gcc-mt-1_49.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include/boost-1_49
LOCAL_CPPFLAGS := -fexceptions
LOCAL_CPPFLAGS += -frtti
LOCAL_EXPORT_CPPFLAGS := -fexceptions
LOCAL_EXPORT_CPPFLAGS += -frtti
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := boost_filesystem
LOCAL_MODULE_FILENAME := boost_filesystem-gcc-mt-1_49
LOCAL_SRC_FILES := libs/$(TARGET_ARCH_ABI)/build/lib/libboost_filesystem-gcc-mt-1_49.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include/boost-1_49
LOCAL_CPPFLAGS := -fexceptions
LOCAL_CPPFLAGS += -frtti
LOCAL_EXPORT_CPPFLAGS := -fexceptions
LOCAL_EXPORT_CPPFLAGS += -frtti
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := boost_iostreams
LOCAL_MODULE_FILENAME := boost_iostreams-gcc-mt-1_49
LOCAL_SRC_FILES := libs/$(TARGET_ARCH_ABI)/build/lib/libboost_iostreams-gcc-mt-1_49.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include/boost-1_49
LOCAL_CPPFLAGS := -fexceptions
LOCAL_CPPFLAGS += -frtti
LOCAL_EXPORT_CPPFLAGS := -fexceptions
LOCAL_EXPORT_CPPFLAGS += -frtti
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := boost_program_options
LOCAL_MODULE_FILENAME := boost_program_options-gcc-mt-1_49
LOCAL_SRC_FILES := libs/$(TARGET_ARCH_ABI)/build/lib/libboost_program_options-gcc-mt-1_49.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include/boost-1_49
LOCAL_CPPFLAGS := -fexceptions
LOCAL_CPPFLAGS += -frtti
LOCAL_EXPORT_CPPFLAGS := -fexceptions
LOCAL_EXPORT_CPPFLAGS += -frtti
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := boost_regex
LOCAL_MODULE_FILENAME := boost_regex-gcc-mt-1_49
LOCAL_SRC_FILES := libs/$(TARGET_ARCH_ABI)/build/lib/libboost_regex-gcc-mt-1_49.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include/boost-1_49
LOCAL_CPPFLAGS := -fexceptions
LOCAL_CPPFLAGS += -frtti
LOCAL_EXPORT_CPPFLAGS := -fexceptions
LOCAL_EXPORT_CPPFLAGS += -frtti
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := boost_signals
LOCAL_MODULE_FILENAME := boost_signals-gcc-mt-1_49
LOCAL_SRC_FILES := libs/$(TARGET_ARCH_ABI)/build/lib/libboost_signals-gcc-mt-1_49.a 
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include/boost-1_49
LOCAL_CPPFLAGS := -fexceptions
LOCAL_CPPFLAGS += -frtti
LOCAL_EXPORT_CPPFLAGS := -fexceptions
LOCAL_EXPORT_CPPFLAGS += -frtti
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := boost_system
LOCAL_MODULE_FILENAME := boost_system-gcc-mt-1_49
LOCAL_SRC_FILES := libs/$(TARGET_ARCH_ABI)/build/lib/libboost_system-gcc-mt-1_49.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include/boost-1_49
LOCAL_CPPFLAGS := -fexceptions
LOCAL_CPPFLAGS += -frtti
LOCAL_EXPORT_CPPFLAGS := -fexceptions
LOCAL_EXPORT_CPPFLAGS += -frtti
include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := boost_thread
LOCAL_MODULE_FILENAME := boost_thread-gcc-mt-1_49
LOCAL_SRC_FILES := libs/$(TARGET_ARCH_ABI)/build/lib/libboost_thread-gcc-mt-1_49.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include/boost-1_49
LOCAL_CPPFLAGS := -fexceptions
LOCAL_CPPFLAGS += -frtti
LOCAL_EXPORT_CPPFLAGS := -fexceptions
LOCAL_EXPORT_CPPFLAGS += -frtti
include $(PREBUILT_STATIC_LIBRARY)