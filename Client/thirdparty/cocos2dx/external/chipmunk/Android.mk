LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := chipmunk_static

LOCAL_MODULE_FILENAME := libchipmunk

LOCAL_SRC_FILES := libs/$(TARGET_ARCH_ABI)/libchipmunk.a

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include/chipmunk

LOCAL_C_INCLUDES := $(LOCAL_PATH)/include/chipmunk
LOCAL_CFLAGS := -std=c99
                                 
include $(PREBUILT_STATIC_LIBRARY)
