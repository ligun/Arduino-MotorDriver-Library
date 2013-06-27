Arduino-MotorDriverLibrary
--------------------------
このライブラリはArduinoでDCモータードライバTA7291Pを制御するためのライブラリです。  
このICは制御信号2つとPWMでDCモーターを操作するのでそのままライブラリなしでも大した記述じゃありませんが、複数個のモーターを使用するときにまとめていたほうが便利だったので作成しました。

##インストール方法
ライブラリのフォルダを自分のArduinoフォルダのlibrariesというフォルダの中に入れてください。

##使用方法
本ライブラリはC++で書かれています。  
まず、グローバルな領域でクラスのインスタンス化を行います。  
コンストラクタの引数は3つで制御ピン1、制御ピン2、PWMピンです。
PWMピンはPWMの使えるピン番号にしてください。  
`MotorDriver driver(1,2,3);`  
PWMピンの指定は省略することができます。  
その場合は速度が常に最大になります。(VREFに何も繋げない)  
`MotorDriver driver(1,2)`  
  
forward,back,stop,brakeの関数によりモーターを制御します。  

###void MotorDriver::forward(uint8_t speed)
forward関数はモーターを正転させます。  
引数は速度で0~255の整数を入れます。引数は省略可能でその場合は最大速度(255)になります。

###void MotorDriver::reverse(uint8_t speed)
forward関数はモーターを逆転させます。  
引数は速度で0~255の整数を入れます。引数は省略可能でその場合は最大速度(255)になります。

###void MotorDriver::stop()
forward関数はモーターを停止させます。  
引数はありません。

###void MotorDriver::forward()
forward関数はモーターに回生ブレーキをかけます。  
引数はありません。

###void MotorDriver::driver(DriveMode mode,uint8_t speed)
モーター駆動を制御します。  
modeに入れた種別により、正転・反転・停止・ブレーキの動作が変わります。  
この関数は作者のプログラムの互換性維持のために残しているためなるべく使わないでください。

##バージョン
###2013.6.27 Ver1.0

###2013.6.28 Ver1.1
モーター逆転の関数名をreverseに変更
