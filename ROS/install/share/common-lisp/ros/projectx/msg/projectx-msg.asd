
(cl:in-package :asdf)

(defsystem "projectx-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "MotorOutSingleArray" :depends-on ("_package_MotorOutSingleArray"))
    (:file "_package_MotorOutSingleArray" :depends-on ("_package"))
    (:file "DataControl" :depends-on ("_package_DataControl"))
    (:file "_package_DataControl" :depends-on ("_package"))
    (:file "Tabpage" :depends-on ("_package_Tabpage"))
    (:file "_package_Tabpage" :depends-on ("_package"))
    (:file "MotorOutArray" :depends-on ("_package_MotorOutArray"))
    (:file "_package_MotorOutArray" :depends-on ("_package"))
    (:file "XYPad" :depends-on ("_package_XYPad"))
    (:file "_package_XYPad" :depends-on ("_package"))
    (:file "Label" :depends-on ("_package_Label"))
    (:file "_package_Label" :depends-on ("_package"))
    (:file "MotorIn" :depends-on ("_package_MotorIn"))
    (:file "_package_MotorIn" :depends-on ("_package"))
    (:file "TouchOSC_Common" :depends-on ("_package_TouchOSC_Common"))
    (:file "_package_TouchOSC_Common" :depends-on ("_package"))
    (:file "OscData" :depends-on ("_package_OscData"))
    (:file "_package_OscData" :depends-on ("_package"))
    (:file "MultiButton" :depends-on ("_package_MultiButton"))
    (:file "_package_MultiButton" :depends-on ("_package"))
    (:file "MultiXYPad" :depends-on ("_package_MultiXYPad"))
    (:file "_package_MultiXYPad" :depends-on ("_package"))
    (:file "IntArray" :depends-on ("_package_IntArray"))
    (:file "_package_IntArray" :depends-on ("_package"))
    (:file "CommonProperties" :depends-on ("_package_CommonProperties"))
    (:file "_package_CommonProperties" :depends-on ("_package"))
    (:file "Sensor" :depends-on ("_package_Sensor"))
    (:file "_package_Sensor" :depends-on ("_package"))
    (:file "ScalableControl" :depends-on ("_package_ScalableControl"))
    (:file "_package_ScalableControl" :depends-on ("_package"))
    (:file "Hash" :depends-on ("_package_Hash"))
    (:file "_package_Hash" :depends-on ("_package"))
    (:file "MultiFader" :depends-on ("_package_MultiFader"))
    (:file "_package_MultiFader" :depends-on ("_package"))
    (:file "MotorOut" :depends-on ("_package_MotorOut"))
    (:file "_package_MotorOut" :depends-on ("_package"))
    (:file "Gyro" :depends-on ("_package_Gyro"))
    (:file "_package_Gyro" :depends-on ("_package"))
    (:file "MotorInArray" :depends-on ("_package_MotorInArray"))
    (:file "_package_MotorInArray" :depends-on ("_package"))
  ))