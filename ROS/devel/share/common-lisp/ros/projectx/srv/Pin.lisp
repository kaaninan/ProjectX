; Auto-generated. Do not edit!


(cl:in-package projectx-srv)


;//! \htmlinclude Pin-request.msg.html

(cl:defclass <Pin-request> (roslisp-msg-protocol:ros-message)
  ((name
    :reader name
    :initarg :name
    :type cl:string
    :initform ""))
)

(cl:defclass Pin-request (<Pin-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Pin-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Pin-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name projectx-srv:<Pin-request> is deprecated: use projectx-srv:Pin-request instead.")))

(cl:ensure-generic-function 'name-val :lambda-list '(m))
(cl:defmethod name-val ((m <Pin-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader projectx-srv:name-val is deprecated.  Use projectx-srv:name instead.")
  (name m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Pin-request>) ostream)
  "Serializes a message object of type '<Pin-request>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'name))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Pin-request>) istream)
  "Deserializes a message object of type '<Pin-request>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Pin-request>)))
  "Returns string type for a service object of type '<Pin-request>"
  "projectx/PinRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Pin-request)))
  "Returns string type for a service object of type 'Pin-request"
  "projectx/PinRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Pin-request>)))
  "Returns md5sum for a message object of type '<Pin-request>"
  "4c2da9f3044fef1a8aa9af34b73c7dbd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Pin-request)))
  "Returns md5sum for a message object of type 'Pin-request"
  "4c2da9f3044fef1a8aa9af34b73c7dbd")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Pin-request>)))
  "Returns full string definition for message of type '<Pin-request>"
  (cl:format cl:nil "string name~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Pin-request)))
  "Returns full string definition for message of type 'Pin-request"
  (cl:format cl:nil "string name~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Pin-request>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'name))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Pin-request>))
  "Converts a ROS message object to a list"
  (cl:list 'Pin-request
    (cl:cons ':name (name msg))
))
;//! \htmlinclude Pin-response.msg.html

(cl:defclass <Pin-response> (roslisp-msg-protocol:ros-message)
  ((pin
    :reader pin
    :initarg :pin
    :type cl:integer
    :initform 0))
)

(cl:defclass Pin-response (<Pin-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Pin-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Pin-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name projectx-srv:<Pin-response> is deprecated: use projectx-srv:Pin-response instead.")))

(cl:ensure-generic-function 'pin-val :lambda-list '(m))
(cl:defmethod pin-val ((m <Pin-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader projectx-srv:pin-val is deprecated.  Use projectx-srv:pin instead.")
  (pin m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Pin-response>) ostream)
  "Serializes a message object of type '<Pin-response>"
  (cl:let* ((signed (cl:slot-value msg 'pin)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Pin-response>) istream)
  "Deserializes a message object of type '<Pin-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'pin) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Pin-response>)))
  "Returns string type for a service object of type '<Pin-response>"
  "projectx/PinResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Pin-response)))
  "Returns string type for a service object of type 'Pin-response"
  "projectx/PinResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Pin-response>)))
  "Returns md5sum for a message object of type '<Pin-response>"
  "4c2da9f3044fef1a8aa9af34b73c7dbd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Pin-response)))
  "Returns md5sum for a message object of type 'Pin-response"
  "4c2da9f3044fef1a8aa9af34b73c7dbd")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Pin-response>)))
  "Returns full string definition for message of type '<Pin-response>"
  (cl:format cl:nil "int64 pin~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Pin-response)))
  "Returns full string definition for message of type 'Pin-response"
  (cl:format cl:nil "int64 pin~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Pin-response>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Pin-response>))
  "Converts a ROS message object to a list"
  (cl:list 'Pin-response
    (cl:cons ':pin (pin msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'Pin)))
  'Pin-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'Pin)))
  'Pin-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Pin)))
  "Returns string type for a service object of type '<Pin>"
  "projectx/Pin")