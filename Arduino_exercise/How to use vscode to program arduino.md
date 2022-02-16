# How to use the vscode for arduino

>As we all know, the arduino IDE is great for beginners. However, if we want to program a larger project, the IDE is not suitable.  
Sometime we need to debug or look up some function,  maybe we can use the VScode to develop it.  
OK. The key is how to use VScode(about it, if you are interested in learning about the vscode, you may use the google or wiki or bing).  
****

1. Install the vscode from the micrsoft  [download the vscode](https://code.visualstudio.com/)  :  
This is easy, yes? If you need to learn the install of vscode, I think there are a lot of tutorials on this aspect on the Internet. I won't dwell on it.  
  
2. Install the expand for arduino in vscode:  
We can press the key:`Ctrl`+`Shift`+`X`, open the extension and search arduino. Then, install it.  
![](https://github.com/wujinhjun/wujinhjuns-openhardware/blob/main/pic/arduino/pic_1/vsforarduino%20(2).png)  
  
3. Configure the extension:  
We can press:  `Ctrl`+`,` to open the setting, then click on the top right corner to edit the json  
![](https://github.com/wujinhjun/wujinhjuns-openhardware/blob/main/pic/arduino/pic_1/vsforarduino%20(3)_LI.jpg)  
  
4. Edit the json:
edit the Path: we will change the `arduino.path:` to the installation of the IDE path. Because vscode is a editor, not the IDE, vscode need to invoke the IDE to work.  
![](https://github.com/wujinhjun/wujinhjuns-openhardware/blob/main/pic/arduino/pic_1/vsforarduino%20(4).png)  
For convinence, you can copy this script. And the "`E:/arduinoIDE/Arduino`" is my installation of the IDE, you need to change it to yours.  

```
    "arduino.path": "E:/arduinoIDE/Arduino", 
    "C_Cpp.intelliSenseEngine": "Tag Parser", 
    "editor.insertSpaces": true, 
    "files.autoGuessEncoding": true, 
    "arduino.logLevel": "info", 
    "explorer.confirmDelete": false, 
    "editor.detectIndentation": false,
```

5. Edit the `c_cpp_properties.json`:
This is an important step, then we can edit the `.vscoe/c_cpp_properties.json`. If you don't have it, you can create a new folder in the main folder.  
If you want to have a good experience, it is necessary to edit it.  
![](https://github.com/wujinhjun/wujinhjuns-openhardware/blob/main/pic/arduino/pic_1/vsforarduino%20(6).png)  
For convinence, you can copy this:(but it is worth mentioning that the path of installation need to be changed to you own)  
My path of installation is: "`E:/arduinoIDE/Arduino`", maybe you can use the `Ctrl` + `F` to find and then change  
And the `"C:/Users/wujinhjun/Documents/Arduino/libraries"` is path of the .ZIP Library. If you have add .ZIP library, you may need to edit this line(If you have not, you can delete it). Same as before, the `wujinhjun` in `C:/Users/wujinhjun/Documents/Arduino/libraries` is my username, which need to be changed to you own  
```
    {
        "configurations": [
            {
                "name": "Win32",
                "includePath": [
                    "E:/arduinoIDE/Arduino/libraries",
                    "E:/arduinoIDE/Arduino/hardware/arduino/avr/**",
                    "E:/arduinoIDE/Arduino/hardware/tools/avr/avr/include",
                    "E:/arduinoIDE/Arduino/hardware/tools/avr/lib/gcc/avr/7.3.0/include",
                    "E:/arduinoIDE/Arduino/hardware/tools/avr/lib/gcc/avr/7.3.0/include-fixed",
                    "E:/arduinoIDE/Arduino/tools/**"
                ],
                "forcedInclude": [
                    "E:/arduinoIDE/Arduino/hardware/arduino/avr/cores/arduino/Arduino.h"
                ],
                "browse": {
                    "limitSymbolsToIncludedHeaders": true,
                    "path": [
                        "E:/arduinoIDE/Arduino/libraries",
                        "C:/Users/wujinhjun/Documents/Arduino/libraries"
                    ]
                },
                "intelliSenseMode": "msvc-x64",
                "defines": [
                    "USBCON"
                ]
            }
        ],
        "version": 4
    }
```

6. The process is finished
![](https://github.com/wujinhjun/wujinhjuns-openhardware/blob/main/pic/arduino/pic_1/vsforarduino%20(7).png)  
****
### Q&A:
1. Where is the `Serial Monitor`:  
   You can find a plug icon in the bottom right conner. By clicking on it, the serial will be opened.  
   ![](https://github.com/wujinhjun/wujinhjuns-openhardware/blob/main/pic/arduino/pic_1/Inkedvsforarduino(8)_LI.jpg)  
2. How to send text in Serial:  
   Press `F1`，and then search the `serial`, choose the `Send Text to serial`. Then you can send text to you arduino.  
   Of course, this is inconvenient. So, I usually use other tools for serial debugging.  
   ![](https://github.com/wujinhjun/wujinhjuns-openhardware/blob/main/pic/arduino/pic_1/Inkedvsforarduino(9)_LI.jpg)  
