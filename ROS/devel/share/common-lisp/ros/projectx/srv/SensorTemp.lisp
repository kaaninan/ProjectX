; Auto-generated. Do not edit!


(cl:in-package projectx-srv)


;//! \htmlinclude SensorTemp-request.msg.html

(cl:defclass <SensorTemp-request> (roslisp-msg-protocol:ros-message)
  ()
)

(cl:defclass SensorTemp-request (<SensorTemp-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SensorTemp-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SensorTemp-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name projectx-srv:<SensorTemp-request> is deprecated: use projectx-srv:SensorTemp-request instead.")))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SensorTemp-request>) ostream)
  "Serializes a message object of type '<SensorTemp-request>"
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SensorTemp-request>) istream)
  "Deserializes a message object of type '<SensorTemp-request>"
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SensorTemp-request>)))
  "Returns string type for a service object of type '<SensorTemp-request>"
  "projectx/SensorTempRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SensorTemp-request)))
  "Returns string type for a service object of type 'SensorTemp-request"
  "projectx/SensorTempRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SensorTemp-request>)))
  "Returns md5sum for a message object of type '<SensorTemp-request>"
  "813b115f2598f32dc74cb170a02d630f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SensorTemp-request)))
  "Returns md5sum for a message object of type 'SensorTemp-request"
  "813b115f2598f32dc74cb170a02d630f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SensorTemp-request>)))
  "Returns full string definition for message of type '<SensorTemp-request>"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SensorTemp-request)))
  "Returns full string definition for message of type 'SensorTemp-request"
  (cl:format cl:nil "~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SensorTemp-request>))
  (cl:+ 0
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SensorTemp-request>))
  "Converts a ROS message object to a list"
  (cl:list 'SensorTemp-request
))
;//! \htmlinclude SensorTemp-response.msg.html

(cl:defclass <SensorTemp-response> (roslisp-msg-protocol:ros-message)
  ((temp1
    :reader temp1
    :initarg :temp1
    :type cl:float
    :initform 0.0)
   (temp2
    :reader temp2
    :initarg :temp2
    :type cl:float
    :initform 0.0)
   (nem
    :reader nem
    :initarg :nem
    :type cl:float
    :initform 0.0))
)

(cl:defclass SensorTemp-response (<SensorTemp-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <SensorTemp-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'SensorTemp-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name projectx-srv:<SensorTemp-response> is deprecated: use projectx-srv:SensorTemp-response instead.")))

(cl:ensure-generic-function 'temp1-val :lambda-list '(m))
(cl:defmethod temp1-val ((m <SensorTemp-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader projectx-srv:temp1-val is deprecated.  Use projectx-srv:temp1 instead.")
  (temp1 m))

(cl:ensure-generic-function 'temp2-val :lambda-list '(m))
(cl:defmethod temp2-val ((m <SensorTemp-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader projectx-srv:temp2-val is deprecated.  Use projectx-srv:temp2 instead.")
  (temp2 m))

(cl:ensure-generic-function 'nem-val :lambda-list '(m))
(cl:defmethod nem-val ((m <SensorTemp-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader projectx-srv:nem-val is deprecated.  Use projectx-srv:nem instead.")
  (nem m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <SensorTemp-response>) ostream)
  "Serializes a message object of type '<SensorTemp-response>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'temp1))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'temp2))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'nem))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <SensorTemp-response>) istream)
  "Deserializes a message object of type '<SensorTemp-response>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'temp1) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'temp2) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'nem) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<SensorTemp-response>)))
  "Returns string type for a service object of type '<SensorTemp-response>"
  "projectx/SensorTempResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SensorTemp-response)))
  "Returns string type for a service object of type 'SensorTemp-response"
  "projectx/SensorTempResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<SensorTemp-response>)))
  "Returns md5sum for a message object of type '<SensorTemp-response>"
  "813b115f2598f32dc74cb170a02d630f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'SensorTemp-response)))
  "Returns md5sum for a message object of type 'SensorTemp-response"
  "813b115f2598f32dc74cb170a02d630f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<SensorTemp-response>)))
  "Returns full string definition for message of type '<SensorTemp-response>"
  (cl:format cl:nil "float64 temp1~%float64 temp2~%float64 nem~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'SensorTemp-response)))
  "Returns full string definition for message of type 'SensorTemp-response"
  (cl:format cl:nil "float64 temp1~%float64 temp2~%float64 nem~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <SensorTemp-response>))
  (cl:+ 0
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <SensorTemp-response>))
  "Converts a ROS message object to a list"
  (cl:list 'SensorTemp-response
    (cl:cons ':temp1 (temp1 msg))
    (cl:cons ':temp2 (temp2 msg))
    (cl:cons ':nem (nem msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'SensorTemp)))
  'SensorTemp-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'SensorTemp)))
  'SensorTemp-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'SensorTemp)))
  "Returns string type for a service object of type '<SensorTemp>"
  "projectx/SensorTemp")