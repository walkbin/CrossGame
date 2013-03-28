/****************************************************************************
Copyright (c) 2010-2012 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
package com.walkbin.yaoyao;

import org.cocos2dx.lib.Cocos2dxActivity;

import com.umeng.update.UmengUpdateAgent;
import com.umeng.update.UmengUpdateListener;
import com.umeng.update.UpdateResponse;

import android.os.Bundle;
import android.widget.Toast;

public class Yaoyao extends Cocos2dxActivity{

	protected void onCreate(Bundle savedInstanceState){
		super.onCreate(savedInstanceState);
		//友盟自更新
		UmengUpdateAgent.setUpdateOnlyWifi(false);
		UmengUpdateAgent.update(this);
		
		UmengUpdateAgent.setUpdateAutoPopup(false); 
		UmengUpdateAgent.setUpdateListener(new UmengUpdateListener() { 
			@Override 
			public void onUpdateReturned(int updateStatus,UpdateResponse updateInfo) {
/*				switch (updateStatus) { 
				case 0: // has update 
					UmengUpdateAgent.showUpdateDialog(mContext, updateInfo); break; 
				case 1: // has no update 
					Toast.makeText(mContext, "没有更新", Toast.LENGTH_SHORT) .show(); break; 
				case 2: // none wifi 
					Toast.makeText(mContext, "没有wifi连接， 只在wifi下更新", Toast.LENGTH_SHORT) .show(); break; 
				case 3: // time out 
					Toast.makeText(mContext, "超时", Toast.LENGTH_SHORT) .show(); break; 
					}*/
			}
		}
		
	}
	
    static {
         System.loadLibrary("game");
    }
}
