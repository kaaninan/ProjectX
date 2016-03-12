; Auto-generated. Do not edit!


(cl:in-package projectx-msg)


;//! \htmlinclude Hash.msg.html

(cl:defclass <Hash> (roslisp-msg-protocol:ros-message)
  ((id
    :reader id
    :initarg :id
    :type cl:integer
    :initform 0)
   (deger
    :reader deger
    :initarg :deger
    :type cl:integer
    :initform 0))
)

(cl:defclass Hash (<Hash>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <Hash>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'Hash)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name projectx-msg:<Hash> is deprecated: use projectx-msg:Hash instead.")))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <Hash>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader projectx-msg:id-val is deprecated.  Use projectx-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'deger-val :lambda-list '(m))
(cl:defmethod deger-val ((m <Hash>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader projectx-msg:deger-val is deprecated.  Use projectx-msg:deger instead.")
  (deger m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <Hash>) ostream)
  "Serializes a message object of type '<Hash>"
  (cl:let* ((signed (cl:slot-value msg 'id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'deger)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <Hash>) istream)
  "Deserializes a message object of type '<Hash>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'id) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'deger) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<Hash>)))
  "Returns string type for a message object of type '<Hash>"
  "projectx/Hash")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'Hash)))
  "Returns string type for a message object of type 'Hash"
  "projectx/Hash")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<Hash>)))
  "Returns md5sum for a message object of type '<Hash>"
  "c58586854baf73aa03696ec20686d5f2")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'Hash)))
  "Returns md5sum for a message object of type 'Hash"
  "c58586854baf73aa03696ec20686d5f2")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<Hash>)))
  "Returns full string definition for message of type '<Hash>"
  (cl:format cl:nil "int64 id~%int64 deger~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'Hash)))
  "Returns full string definition for message of type 'Hash"
  (cl:format cl:nil "int64 id~%int64 deger~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <Hash>))
  (cl:+ 0
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <Hash>))
  "Converts a ROS message object to a list"
  (cl:list 'Hash
    (cl:cons ':id (id msg))
    (cl:cons ':deger (deger msg))
))
