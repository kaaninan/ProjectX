; Auto-generated. Do not edit!


(cl:in-package touchosc_msgs-msg)


;//! \htmlinclude TouchOSC_Common.msg.html

(cl:defclass <TouchOSC_Common> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (common
    :reader common
    :initarg :common
    :type touchosc_msgs-msg:CommonProperties
    :initform (cl:make-instance 'touchosc_msgs-msg:CommonProperties)))
)

(cl:defclass TouchOSC_Common (<TouchOSC_Common>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <TouchOSC_Common>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'TouchOSC_Common)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name touchosc_msgs-msg:<TouchOSC_Common> is deprecated: use touchosc_msgs-msg:TouchOSC_Common instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <TouchOSC_Common>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader touchosc_msgs-msg:header-val is deprecated.  Use touchosc_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'common-val :lambda-list '(m))
(cl:defmethod common-val ((m <TouchOSC_Common>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader touchosc_msgs-msg:common-val is deprecated.  Use touchosc_msgs-msg:common instead.")
  (common m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <TouchOSC_Common>) ostream)
  "Serializes a message object of type '<TouchOSC_Common>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'common) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <TouchOSC_Common>) istream)
  "Deserializes a message object of type '<TouchOSC_Common>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'common) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<TouchOSC_Common>)))
  "Returns string type for a message object of type '<TouchOSC_Common>"
  "touchosc_msgs/TouchOSC_Common")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'TouchOSC_Common)))
  "Returns string type for a message object of type 'TouchOSC_Common"
  "touchosc_msgs/TouchOSC_Common")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<TouchOSC_Common>)))
  "Returns md5sum for a message object of type '<TouchOSC_Common>"
  "02b274e5694f91306b366760eaca24ef")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'TouchOSC_Common)))
  "Returns md5sum for a message object of type 'TouchOSC_Common"
  "02b274e5694f91306b366760eaca24ef")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<TouchOSC_Common>)))
  "Returns full string definition for message of type '<TouchOSC_Common>"
  (cl:format cl:nil "# TouchOSC Common Control~%# Battery, Time~%~%Header header~%CommonProperties common~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: touchosc_msgs/CommonProperties~%# Common functionality to all TouchOSC controls~%~%string tabpage          # Control tabpage~%string name             # Control Name~%int16 x                 # X position of the control~%int16 y                 # Y position of the control~%uint16 width            # Width of the control~%uint16 height           # Height of the control~%string visible          # Visibility of the control~%~%# Possible colors are:~%# \"red\", \"green\", \"blue\", \"yellow\", \"orange\", \"purple\", \"gray\"~%string color            # Color of the control~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'TouchOSC_Common)))
  "Returns full string definition for message of type 'TouchOSC_Common"
  (cl:format cl:nil "# TouchOSC Common Control~%# Battery, Time~%~%Header header~%CommonProperties common~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: touchosc_msgs/CommonProperties~%# Common functionality to all TouchOSC controls~%~%string tabpage          # Control tabpage~%string name             # Control Name~%int16 x                 # X position of the control~%int16 y                 # Y position of the control~%uint16 width            # Width of the control~%uint16 height           # Height of the control~%string visible          # Visibility of the control~%~%# Possible colors are:~%# \"red\", \"green\", \"blue\", \"yellow\", \"orange\", \"purple\", \"gray\"~%string color            # Color of the control~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <TouchOSC_Common>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'common))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <TouchOSC_Common>))
  "Converts a ROS message object to a list"
  (cl:list 'TouchOSC_Common
    (cl:cons ':header (header msg))
    (cl:cons ':common (common msg))
))
