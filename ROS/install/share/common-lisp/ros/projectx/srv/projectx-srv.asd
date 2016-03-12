
(cl:in-package :asdf)

(defsystem "projectx-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "MotorBoost" :depends-on ("_package_MotorBoost"))
    (:file "_package_MotorBoost" :depends-on ("_package"))
    (:file "SensorTemp" :depends-on ("_package_SensorTemp"))
    (:file "_package_SensorTemp" :depends-on ("_package"))
    (:file "Speech" :depends-on ("_package_Speech"))
    (:file "_package_Speech" :depends-on ("_package"))
  ))