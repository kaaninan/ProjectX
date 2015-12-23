; Auto-generated. Do not edit!


(cl:in-package projectx-msg)


;//! \htmlinclude MultiXYPad.msg.html

(cl:defclass <MultiXYPad> (roslisp-msg-protocol:ros-message)
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
   (x
    :reader x
    :initarg :x
    :type (cl:vector cl:float)
   :initform (cl:make-array 5 :element-type 'cl:float :initial-element 0.0))
   (y
    :reader y
    :initarg :y
    :type (cl:vector cl:float)
   :initform (cl:make-array 5 :element-type 'cl:float :initial-element 0.0))
   (z
    :reader z
    :initarg :z
    :type (cl:vector cl:boolean)
   :initform (cl:make-array 5 :element-type 'cl:boolean :initial-element cl:nil)))
)

(cl:defclass MultiXYPad (<MultiXYPad>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MultiXYPad>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MultiXYPad)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name projectx-msg:<MultiXYPad> is deprecated: use projectx-msg:MultiXYPad instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <MultiXYPad>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader projectx-msg:header-val is deprecated.  Use projectx-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'common-val :lambda-list '(m))
(cl:defmethod common-val ((m <MultiXYPad>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader projectx-msg:common-val is deprecated.  Use projectx-msg:common instead.")
  (common m))

(cl:ensure-generic-function 'range-val :lambda-list '(m))
(cl:defmethod range-val ((m <MultiXYPad>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader projectx-msg:range-val is deprecated.  Use projectx-msg:range instead.")
  (range m))

(cl:ensure-generic-function 'x-val :lambda-list '(m))
(cl:defmethod x-val ((m <MultiXYPad>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader projectx-msg:x-val is deprecated.  Use projectx-msg:x instead.")
  (x m))

(cl:ensure-generic-function 'y-val :lambda-list '(m))
(cl:defmethod y-val ((m <MultiXYPad>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader projectx-msg:y-val is deprecated.  Use projectx-msg:y instead.")
  (y m))

(cl:ensure-generic-function 'z-val :lambda-list '(m))
(cl:defmethod z-val ((m <MultiXYPad>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader projectx-msg:z-val is deprecated.  Use projectx-msg:z instead.")
  (z m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MultiXYPad>) ostream)
  "Serializes a message object of type '<MultiXYPad>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'common) ostream)
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'range))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'x))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-single-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)))
   (cl:slot-value msg 'y))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if ele 1 0)) ostream))
   (cl:slot-value msg 'z))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MultiXYPad>) istream)
  "Deserializes a message object of type '<MultiXYPad>"
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
  (cl:setf (cl:slot-value msg 'x) (cl:make-array 5))
  (cl:let ((vals (cl:slot-value msg 'x)))
    (cl:dotimes (i 5)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
  (cl:setf (cl:slot-value msg 'y) (cl:make-array 5))
  (cl:let ((vals (cl:slot-value msg 'y)))
    (cl:dotimes (i 5)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-single-float-bits bits)))))
  (cl:setf (cl:slot-value msg 'z) (cl:make-array 5))
  (cl:let ((vals (cl:slot-value msg 'z)))
    (cl:dotimes (i 5)
    (cl:setf (cl:aref vals i) (cl:not (cl:zerop (cl:read-byte istream))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MultiXYPad>)))
  "Returns string type for a message object of type '<MultiXYPad>"
  "projectx/MultiXYPad")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MultiXYPad)))
  "Returns string type for a message object of type 'MultiXYPad"
  "projectx/MultiXYPad")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MultiXYPad>)))
  "Returns md5sum for a message object of type '<MultiXYPad>"
  "9c4c914fe2ffb44766fc5338b5a82aba")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MultiXYPad)))
  "Returns md5sum for a message object of type 'MultiXYPad"
  "9c4c914fe2ffb44766fc5338b5a82aba")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MultiXYPad>)))
  "Returns full string definition for message of type '<MultiXYPad>"
  (cl:format cl:nil "# TouchOSC MultiXYPad Control~%~%Header header~%CommonProperties common~%float32[2] range~%float32[5] x~%float32[5] y~%bool[5] z~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: projectx/CommonProperties~%# Common functionality to all TouchOSC controls~%~%string tabpage          # Control tabpage~%string name             # Control Name~%int16 x                 # X position of the control~%int16 y                 # Y position of the control~%uint16 width            # Width of the control~%uint16 height           # Height of the control~%string visible          # Visibility of the control~%~%# Possible colors are:~%# \"red\", \"green\", \"blue\", \"yellow\", \"orange\", \"purple\", \"gray\"~%string color            # Color of the control~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MultiXYPad)))
  "Returns full string definition for message of type 'MultiXYPad"
  (cl:format cl:nil "# TouchOSC MultiXYPad Control~%~%Header header~%CommonProperties common~%float32[2] range~%float32[5] x~%float32[5] y~%bool[5] z~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%================================================================================~%MSG: projectx/CommonProperties~%# Common functionality to all TouchOSC controls~%~%string tabpage          # Control tabpage~%string name             # Control Name~%int16 x                 # X position of the control~%int16 y                 # Y position of the control~%uint16 width            # Width of the control~%uint16 height           # Height of the control~%string visible          # Visibility of the control~%~%# Possible colors are:~%# \"red\", \"green\", \"blue\", \"yellow\", \"orange\", \"purple\", \"gray\"~%string color            # Color of the control~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MultiXYPad>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'common))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'range) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'x) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'y) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'z) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 1)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MultiXYPad>))
  "Converts a ROS message object to a list"
  (cl:list 'MultiXYPad
    (cl:cons ':header (header msg))
    (cl:cons ':common (common msg))
    (cl:cons ':range (range msg))
    (cl:cons ':x (x msg))
    (cl:cons ':y (y msg))
    (cl:cons ':z (z msg))
))
