; Auto-generated. Do not edit!


(cl:in-package projectx-srv)


;//! \htmlinclude MotorBoost-request.msg.html

(cl:defclass <MotorBoost-request> (roslisp-msg-protocol:ros-message)
  ((in
    :reader in
    :initarg :in
    :type cl:string
    :initform ""))
)

(cl:defclass MotorBoost-request (<MotorBoost-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MotorBoost-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MotorBoost-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name projectx-srv:<MotorBoost-request> is deprecated: use projectx-srv:MotorBoost-request instead.")))

(cl:ensure-generic-function 'in-val :lambda-list '(m))
(cl:defmethod in-val ((m <MotorBoost-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader projectx-srv:in-val is deprecated.  Use projectx-srv:in instead.")
  (in m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MotorBoost-request>) ostream)
  "Serializes a message object of type '<MotorBoost-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'in))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'in))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MotorBoost-request>) istream)
  "Deserializes a message object of type '<MotorBoost-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'in) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'in) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MotorBoost-request>)))
  "Returns string type for a service object of type '<MotorBoost-request>"
  "projectx/MotorBoostRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MotorBoost-request)))
  "Returns string type for a service object of type 'MotorBoost-request"
  "projectx/MotorBoostRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MotorBoost-request>)))
  "Returns md5sum for a message object of type '<MotorBoost-request>"
  "e21fb7853ad73d6d988d6371d4fed1e2")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MotorBoost-request)))
  "Returns md5sum for a message object of type 'MotorBoost-request"
  "e21fb7853ad73d6d988d6371d4fed1e2")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MotorBoost-request>)))
  "Returns full string definition for message of type '<MotorBoost-request>"
  (cl:format cl:nil "string in~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MotorBoost-request)))
  "Returns full string definition for message of type 'MotorBoost-request"
  (cl:format cl:nil "string in~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MotorBoost-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'in))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MotorBoost-request>))
  "Converts a ROS message object to a list"
  (cl:list 'MotorBoost-request
    (cl:cons ':in (in msg))
))
;//! \htmlinclude MotorBoost-response.msg.html

(cl:defclass <MotorBoost-response> (roslisp-msg-protocol:ros-message)
  ((out
    :reader out
    :initarg :out
    :type cl:string
    :initform ""))
)

(cl:defclass MotorBoost-response (<MotorBoost-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MotorBoost-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MotorBoost-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name projectx-srv:<MotorBoost-response> is deprecated: use projectx-srv:MotorBoost-response instead.")))

(cl:ensure-generic-function 'out-val :lambda-list '(m))
(cl:defmethod out-val ((m <MotorBoost-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader projectx-srv:out-val is deprecated.  Use projectx-srv:out instead.")
  (out m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MotorBoost-response>) ostream)
  "Serializes a message object of type '<MotorBoost-response>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'out))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'out))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MotorBoost-response>) istream)
  "Deserializes a message object of type '<MotorBoost-response>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'out) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'out) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MotorBoost-response>)))
  "Returns string type for a service object of type '<MotorBoost-response>"
  "projectx/MotorBoostResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MotorBoost-response)))
  "Returns string type for a service object of type 'MotorBoost-response"
  "projectx/MotorBoostResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MotorBoost-response>)))
  "Returns md5sum for a message object of type '<MotorBoost-response>"
  "e21fb7853ad73d6d988d6371d4fed1e2")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MotorBoost-response)))
  "Returns md5sum for a message object of type 'MotorBoost-response"
  "e21fb7853ad73d6d988d6371d4fed1e2")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MotorBoost-response>)))
  "Returns full string definition for message of type '<MotorBoost-response>"
  (cl:format cl:nil "string out~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MotorBoost-response)))
  "Returns full string definition for message of type 'MotorBoost-response"
  (cl:format cl:nil "string out~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MotorBoost-response>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'out))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MotorBoost-response>))
  "Converts a ROS message object to a list"
  (cl:list 'MotorBoost-response
    (cl:cons ':out (out msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'MotorBoost)))
  'MotorBoost-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'MotorBoost)))
  'MotorBoost-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MotorBoost)))
  "Returns string type for a service object of type '<MotorBoost>"
  "projectx/MotorBoost")