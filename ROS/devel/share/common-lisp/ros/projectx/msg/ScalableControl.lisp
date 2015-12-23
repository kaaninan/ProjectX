; Auto-generated. Do not edit!


(cl:in-package projectx-msg)


;//! \htmlinclude ScalableControl.msg.html

(cl:defclass <ScalableControl> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (common
    :reader common
    :initarg :common
    :type projectx-msg:CommonProperties
    :initform (cl:make-instance 'projectx-msg:CommonProperties))
   (range
    :reader range
    :initarg :range
    :type (cl:vector cl:float)
   :initform (cl:make-array 2 :element-type 'cl:float :initial-element 0.0))
   (value
    :reader value
    :initarg :value
    :type cl:float
    :initform 0.0)
   (z
    :reader z
    :initarg :z
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass ScalableControl (<ScalableControl>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ScalableControl>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ScalableControl)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name projectx-msg:<ScalableControl> is deprecated: use projectx-msg:ScalableControl instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <ScalableControl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader projectx-msg:header-val is deprecated.  Use projectx-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'common-val :lambda-list '(m))
(cl:defmethod common-val ((m <ScalableControl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader projectx-msg:common-val is deprecated.  Use projectx-msg:common instead.")
  (common m))

(cl:ensure-generic-function 'range-val :lambda-list '(m))
(cl:defmethod range-val ((m <ScalableControl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader projectx-msg:range-val is deprecated.  Use projectx-msg:range instead.")
  (range m))

(cl:ensure-generic-function 'value-val :lambda-list '(m))
(cl:defmethod value-val ((m <ScalableControl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader projectx-msg:value-val is deprecated.  Use projectx-msg:value instead.")
  (value m))

(cl:ensure-generic-function 'z-val :lambda-list '(m))
(cl:defmethod z-val ((m <ScalableControl>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader projectx-msg:z-val is deprecated.  Use projectx-msg:z instead.")
  (z m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ScalableControl>) ostream)
  "Serializes a message object of type '<ScalableControl>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'common) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'range))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'value))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'z) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ScalableControl>) istream)
  "Deserializes a message object of type '<ScalableControl>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'common) istream)
  (cl:setf (cl:slot-value msg 'range) (cl:make-array 2))
  (cl:let ((vals (cl:slot-value msg 'range)))
    (cl:dotimes (i 2)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'value) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:slot-value msg 'z) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ScalableControl>)))
  "Returns string type for a message object of type '<ScalableControl>"
  "projectx/ScalableControl")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ScalableControl)))
  "Returns string type for a message object of type 'ScalableControl"
  "projectx/ScalableControl")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ScalableControl>)))
  "Returns md5sum for a message object of type '<ScalableControl>"
  "4b6ef3bf63f615ec962c83cced2ac5dc")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ScalableControl)))
  "Returns md5sum for a message object of type 'ScalableControl"
  "4b6ef3bf63f615ec962c83cced2ac5dc")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ScalableControl>)))
  "Returns full string definition for message of type '<ScalableControl>"
  (cl:format cl:nil "# TouchOSC Scalable Control~%# Push Button, Toggle Button, LED, Fader, Rotary~%~%Header header~%CommonProperties common~%float32[2] range~%float32 value~%bool z~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: projectx/CommonProperties~%# Common functionality to all TouchOSC controls~%~%string tabpage          # Control tabpage~%string name             # Control Name~%int16 x                 # X position of the control~%int16 y                 # Y position of the control~%uint16 width            # Width of the control~%uint16 height           # Height of the control~%string visible          # Visibility of the control~%~%# Possible colors are:~%# \"red\", \"green\", \"blue\", \"yellow\", \"orange\", \"purple\", \"gray\"~%string color            # Color of the control~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ScalableControl)))
  "Returns full string definition for message of type 'ScalableControl"
  (cl:format cl:nil "# TouchOSC Scalable Control~%# Push Button, Toggle Button, LED, Fader, Rotary~%~%Header header~%CommonProperties common~%float32[2] range~%float32 value~%bool z~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: projectx/CommonProperties~%# Common functionality to all TouchOSC controls~%~%string tabpage          # Control tabpage~%string name             # Control Name~%int16 x                 # X position of the control~%int16 y                 # Y position of the control~%uint16 width            # Width of the control~%uint16 height           # Height of the control~%string visible          # Visibility of the control~%~%# Possible colors are:~%# \"red\", \"green\", \"blue\", \"yellow\", \"orange\", \"purple\", \"gray\"~%string color            # Color of the control~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ScalableControl>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'common))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'range) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ScalableControl>))
  "Converts a ROS message object to a list"
  (cl:list 'ScalableControl
    (cl:cons ':header (header msg))
    (cl:cons ':common (common msg))
    (cl:cons ':range (range msg))
    (cl:cons ':value (value msg))
    (cl:cons ':z (z msg))
))
