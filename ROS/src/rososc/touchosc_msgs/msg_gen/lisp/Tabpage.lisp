; Auto-generated. Do not edit!


(cl:in-package touchosc_msgs-msg)


;//! \htmlinclude Tabpage.msg.html

(cl:defclass <Tabpage> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (tabpage
    :reader tabpage
    :initarg :tabpage
    :type cl:string
    :initform ""))
)

(cl:defclass Tabpage (<Tabpage>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Tabpage>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Tabpage)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name touchosc_msgs-msg:<Tabpage> is deprecated: use touchosc_msgs-msg:Tabpage instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <Tabpage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader touchosc_msgs-msg:header-val is deprecated.  Use touchosc_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'tabpage-val :lambda-list '(m))
(cl:defmethod tabpage-val ((m <Tabpage>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader touchosc_msgs-msg:tabpage-val is deprecated.  Use touchosc_msgs-msg:tabpage instead.")
  (tabpage m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Tabpage>) ostream)
  "Serializes a message object of type '<Tabpage>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'tabpage))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'tabpage))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Tabpage>) istream)
  "Deserializes a message object of type '<Tabpage>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'tabpage) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'tabpage) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Tabpage>)))
  "Returns string type for a message object of type '<Tabpage>"
  "touchosc_msgs/Tabpage")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Tabpage)))
  "Returns string type for a message object of type 'Tabpage"
  "touchosc_msgs/Tabpage")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Tabpage>)))
  "Returns md5sum for a message object of type '<Tabpage>"
  "4213ffb5a43e14111c66fe04a2d8f4ec")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Tabpage)))
  "Returns md5sum for a message object of type 'Tabpage"
  "4213ffb5a43e14111c66fe04a2d8f4ec")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Tabpage>)))
  "Returns full string definition for message of type '<Tabpage>"
  (cl:format cl:nil "# Used for tabpage switching~%~%Header header~%string tabpage~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Tabpage)))
  "Returns full string definition for message of type 'Tabpage"
  (cl:format cl:nil "# Used for tabpage switching~%~%Header header~%string tabpage~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Tabpage>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:length (cl:slot-value msg 'tabpage))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Tabpage>))
  "Converts a ROS message object to a list"
  (cl:list 'Tabpage
    (cl:cons ':header (header msg))
    (cl:cons ':tabpage (tabpage msg))
))
