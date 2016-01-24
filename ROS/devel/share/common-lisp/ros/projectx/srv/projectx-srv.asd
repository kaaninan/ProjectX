
(cl:in-package :asdf)

(defsystem "projectx-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Pin" :depends-on ("_package_Pin"))
    (:file "_package_Pin" :depends-on ("_package"))
    (:file "AddTwoInts" :depends-on ("_package_AddTwoInts"))
    (:file "_package_AddTwoInts" :depends-on ("_package"))
    (:file "MotorBoost" :depends-on ("_package_MotorBoost"))
    (:file "_package_MotorBoost" :depends-on ("_package"))
    (:file "SensorTemp" :depends-on ("_package_SensorTemp"))
    (:file "_package_SensorTemp" :depends-on ("_package"))
  ))