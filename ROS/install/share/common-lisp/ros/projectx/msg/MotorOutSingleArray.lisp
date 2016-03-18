; Auto-generated. Do not edit!


(cl:in-package projectx-msg)


;//! \htmlinclude MotorOutSingleArray.msg.html

(cl:defclass <MotorOutSingleArray> (roslisp-msg-protocol:ros-message)
  ((id
    :reader id
    :initarg :id
    :type (cl:vector cl:integer)
   :initform (cl:make-array 21 :element-type 'cl:integer :initial-element 0))
   (pos
    :reader pos
    :initarg :pos
    :type (cl:vector cl:integer)
   :initform (cl:make-array 21 :element-type 'cl:integer :initial-element 0)))
)

(cl:defclass MotorOutSingleArray (<MotorOutSingleArray>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MotorOutSingleArray>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MotorOutSingleArray)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name projectx-msg:<MotorOutSingleArray> is deprecated: use projectx-msg:MotorOutSingleArray instead.")))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <MotorOutSingleArray>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader projectx-msg:id-val is deprecated.  Use projectx-msg:id instead.")
  (id m))

(cl:ensure-generic-function 'pos-val :lambda-list '(m))
(cl:defmethod pos-val ((m <MotorOutSingleArray>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader projectx-msg:pos-val is deprecated.  Use projectx-msg:pos instead.")
  (pos m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MotorOutSingleArray>) ostream)
  "Serializes a message object of type '<MotorOutSingleArray>"
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let* ((signed ele) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    ))
   (cl:slot-value msg 'id))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let* ((signed ele) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    ))
   (cl:slot-value msg 'pos))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MotorOutSingleArray>) istream)
  "Deserializes a message object of type '<MotorOutSingleArray>"
  (cl:setf (cl:slot-value msg 'id) (cl:make-array 21))
  (cl:let ((vals (cl:slot-value msg 'id)))
    (cl:dotimes (i 21)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))))
  (cl:setf (cl:slot-value msg 'pos) (cl:make-array 21))
  (cl:let ((vals (cl:slot-value msg 'pos)))
    (cl:dotimes (i 21)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MotorOutSingleArray>)))
  "Returns string type for a message object of type '<MotorOutSingleArray>"
  "projectx/MotorOutSingleArray")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MotorOutSingleArray)))
  "Returns string type for a message object of type 'MotorOutSingleArray"
  "projectx/MotorOutSingleArray")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MotorOutSingleArray>)))
  "Returns md5sum for a message object of type '<MotorOutSingleArray>"
  "de04d0ab49b6de06afa1f92fbae073c5")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MotorOutSingleArray)))
  "Returns md5sum for a message object of type 'MotorOutSingleArray"
  "de04d0ab49b6de06afa1f92fbae073c5")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MotorOutSingleArray>)))
  "Returns full string definition for message of type '<MotorOutSingleArray>"
  (cl:format cl:nil "int64[21] id~%int64[21] pos~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MotorOutSingleArray)))
  "Returns full string definition for message of type 'MotorOutSingleArray"
  (cl:format cl:nil "int64[21] id~%int64[21] pos~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MotorOutSingleArray>))
  (cl:+ 0
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'id) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
     0 (cl:reduce #'cl:+ (cl:slot-value msg 'pos) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MotorOutSingleArray>))
  "Converts a ROS message object to a list"
  (cl:list 'MotorOutSingleArray
    (cl:cons ':id (id msg))
    (cl:cons ':pos (pos msg))
))
