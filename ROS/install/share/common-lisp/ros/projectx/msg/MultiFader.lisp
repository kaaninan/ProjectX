; Auto-generated. Do not edit!


(cl:in-package projectx-msg)


;//! \htmlinclude MultiFader.msg.html

(cl:defclass <MultiFader> (roslisp-msg-protocol:ros-message)
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
   (dimension
    :reader dimension
    :initarg :dimension
    :type cl:fixnum
    :initform 0)
   (range
    :reader range
    :initarg :range
    :type (cl:vector cl:float)
   :initform (cl:make-array 2 :element-type 'cl:float :initial-element 0.0))
   (values
    :reader values
    :initarg :values
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0))
   (z
    :reader z
    :initarg :z
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass MultiFader (<MultiFader>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MultiFader>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MultiFader)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name projectx-msg:<MultiFader> is deprecated: use projectx-msg:MultiFader instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <MultiFader>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader projectx-msg:header-val is deprecated.  Use projectx-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'common-val :lambda-list '(m))
(cl:defmethod common-val ((m <MultiFader>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader projectx-msg:common-val is deprecated.  Use projectx-msg:common instead.")
  (common m))

(cl:ensure-generic-function 'dimension-val :lambda-list '(m))
(cl:defmethod dimension-val ((m <MultiFader>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader projectx-msg:dimension-val is deprecated.  Use projectx-msg:dimension instead.")
  (dimension m))

(cl:ensure-generic-function 'range-val :lambda-list '(m))
(cl:defmethod range-val ((m <MultiFader>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader projectx-msg:range-val is deprecated.  Use projectx-msg:range instead.")
  (range m))

(cl:ensure-generic-function 'values-val :lambda-list '(m))
(cl:defmethod values-val ((m <MultiFader>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader projectx-msg:values-val is deprecated.  Use projectx-msg:values instead.")
  (values m))

(cl:ensure-generic-function 'z-val :lambda-list '(m))
(cl:defmethod z-val ((m <MultiFader>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader projectx-msg:z-val is deprecated.  Use projectx-msg:z instead.")
  (z m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MultiFader>) ostream)
  "Serializes a message object of type '<MultiFader>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'common) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'dimension)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'dimension)) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'range))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'values))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'values))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'z) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MultiFader>) istream)
  "Deserializes a message object of type '<MultiFader>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'common) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'dimension)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'dimension)) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'range) (cl:make-array 2))
  (cl:let ((vals (cl:slot-value msg 'range)))
    (cl:dotimes (i 2)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'values) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'values)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits))))))
    (cl:setf (cl:slot-value msg 'z) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MultiFader>)))
  "Returns string type for a message object of type '<MultiFader>"
  "projectx/MultiFader")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MultiFader)))
  "Returns string type for a message object of type 'MultiFader"
  "projectx/MultiFader")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MultiFader>)))
  "Returns md5sum for a message object of type '<MultiFader>"
  "809deaed82ef6d600e6957164fb63431")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MultiFader)))
  "Returns md5sum for a message object of type 'MultiFader"
  "809deaed82ef6d600e6957164fb63431")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MultiFader>)))
  "Returns full string definition for message of type '<MultiFader>"
  (cl:format cl:nil "# TouchOSC Multifader Control~%~%Header header~%CommonProperties common~%uint16 dimension~%float32[2] range~%float32[] values~%bool z~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: projectx/CommonProperties~%# Common functionality to all TouchOSC controls~%~%string tabpage          # Control tabpage~%string name             # Control Name~%int16 x                 # X position of the control~%int16 y                 # Y position of the control~%uint16 width            # Width of the control~%uint16 height           # Height of the control~%string visible          # Visibility of the control~%~%# Possible colors are:~%# \"red\", \"green\", \"blue\", \"yellow\", \"orange\", \"purple\", \"gray\"~%string color            # Color of the control~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MultiFader)))
  "Returns full string definition for message of type 'MultiFader"
  (cl:format cl:nil "# TouchOSC Multifader Control~%~%Header header~%CommonProperties common~%uint16 dimension~%float32[2] range~%float32[] values~%bool z~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: projectx/CommonProperties~%# Common functionality to all TouchOSC controls~%~%string tabpage          # Control tabpage~%string name             # Control Name~%int16 x                 # X position of the control~%int16 y                 # Y position of the control~%uint16 width            # Width of the control~%uint16 height           # Height of the control~%string visible          # Visibility of the control~%~%# Possible colors are:~%# \"red\", \"green\", \"blue\", \"yellow\", \"orange\", \"purple\", \"gray\"~%string color            # Color of the control~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MultiFader>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'common))
     2
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'range) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'values) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MultiFader>))
  "Converts a ROS message object to a list"
  (cl:list 'MultiFader
    (cl:cons ':header (header msg))
    (cl:cons ':common (common msg))
    (cl:cons ':dimension (dimension msg))
    (cl:cons ':range (range msg))
    (cl:cons ':values (values msg))
    (cl:cons ':z (z msg))
))
