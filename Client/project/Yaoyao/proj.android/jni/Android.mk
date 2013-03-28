LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := game_shared
LOCAL_MODULE_FILENAME := libgame

LOCAL_SRC_FILES := \
main.cpp \
../../Classes/assist/DBHelper.cpp\
../../Classes/assist/FileHelper.cpp\
../../Classes/assist/InstanceMgr.cpp\
../../Classes/assist/LoaderHelper.cpp\
../../Classes/base/BaseLayer.cpp\
../../Classes/base/BaseScene.cpp\
../../Classes/base/ControlButtonLoader.cpp\
../../Classes/base/LabelBMFontLoader.cpp\
../../Classes/base/LabelTTFLoader.cpp\
../../Classes/base/LangMgr.cpp\
../../Classes/base/NodeLoaderLibrary.cpp\
../../Classes/controller/UIMgr.cpp\
../../Classes/frame/AppDelegate.cpp\
../../Classes/model/CubeData.cpp\
../../Classes/model/Ground.cpp\
../../Classes/model/MainLogic.cpp\
../../Classes/view/LayerLoading.cpp\
../../Classes/view/LayerLogo.cpp\
../../Classes/view/LayerMain.cpp\
../../Classes/view/RollLargePannel.cpp\
../../Classes/view/RollPannel.cpp\
../../Classes/view/RollSmallPannel.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH) \
						    $(LOCAL_PATH)/../../Classes

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static\
							   cocosdenshion_static\
							   cocos_extension_static\
							   box2d_static

LOCAL_CPPFLAGS += -std=gnu++11
LOCAL_CPPFLAGS += -DCOCOS2D_DEBUG=1
include $(BUILD_SHARED_LIBRARY)

$(call import-module,CocosDenshion/android)
$(call import-module,cocos2dx)
$(call import-module,extensions)
$(call import-module,external/Box2D)