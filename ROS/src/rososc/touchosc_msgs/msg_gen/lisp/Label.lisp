; Auto-generated. Do not edit!


(cl:in-package touchosc_msgs-msg)


;//! \htmlinclude Label.msg.html

(cl:defclass <Label> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (common
    :reader common
    :initarg :common
    :type touchosc_msgs-msg:CommonProperties
    :initform (cl:make-instance 'touchosc_msgs-msg:CommonProperties))
   (value
    :reader value
    :initarg :value
    :type cl:string
    :initform ""))
)

(cl:defclass Label (<Label>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Label>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Label)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name touchosc_msgs-msg:<Label> is deprecated: use touchosc_msgs-msg:Label instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <Label>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader touchosc_msgs-msg:header-val is deprecated.  Use touchosc_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'common-val :lambda-list '(m))
(cl:defmethod common-val ((m <Label>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader touchosc_msgs-msg:common-val is deprecated.  Use touchosc_msgs-msg:common instead.")
  (common m))

(cl:ensure-generic-function 'value-val :lambda-list '(m))
(cl:defmethod value-val ((m <Label>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader touchosc_msgs-msg:value-val is deprecated.  Use touchosc_msgs-msg:value instead.")
  (value m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Label>) ostream)
  "Serializes a message object of type '<Label>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'common) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'value))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'value))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Label>) istream)
  "Deserializes a message object of type '<Label>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'common) istream)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'value) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'value) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Label>)))
  "Returns string type for a message object of type '<Label>"
  "touchosc_msgs/Label")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Label)))
  "Returns string type for a message object of type 'Label"
  "touchosc_msgs/Label")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Label>)))
  "Returns md5sum for a message object of type '<Label>"
  "b5cfc77fbfd3429b0db9743556374f86")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Label)))
  "Returns md5sum for a message object of type 'Label"
  "b5cfc77fbfd3429b0db9743556374f86")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Label>)))
  "Returns full string definition for message of type '<Label>"
  (cl:format cl:nil "# TouchOSC Label Control~%~%Header header~%CommonProperties common~%string value~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: touchosc_msgs/CommonProperties~%# Common functionality to all TouchOSC controls~%~%string tabpage          # Control tabpage~%string name             # Control Name~%int16 x                 # X position of the control~%int16 y                 # Y position of the control~%uint16 width            # Width of the control~%uint16 height           # Height of the control~%string visible          # Visibility of the control~%~%# Possible colors are:~%# \"red\", \"green\", \"blue\", \"yellow\", \"orange\", \"purple\", \"gray\"~%string color            # Color of the control~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Label)))
  "Returns full string definition for message of type 'Label"
  (cl:format cl:nil "# TouchOSC Label Control~%~%Header header~%CommonProperties common~%string value~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: touchosc_msgs/CommonProperties~%# Common functionality to all TouchOSC controls~%~%string tabpage          # Control tabpage~%string name             # Control Name~%int16 x                 # X position of the control~%int16 y                 # Y position of the control~%uint16 width            # Width of the control~%uint16 height           # Height of the control~%string visible          # Visibility of the control~%~%# Possible colors are:~%# \"red\", \"green\", \"blue\", \"yellow\", \"orange\", \"purple\", \"gray\"~%string color            # Color of the control~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Label>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'common))
     4 (cl:length (cl:slot-value msg 'value))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Label>))
  "Converts a ROS message object to a list"
  (cl:list 'Label
    (cl:cons ':header (header msg))
    (cl:cons ':common (common msg))
    (cl:cons ':value (value msg))
))
