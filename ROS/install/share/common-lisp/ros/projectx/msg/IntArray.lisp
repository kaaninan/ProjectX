; Auto-generated. Do not edit!


(cl:in-package projectx-msg)


;//! \htmlinclude IntArray.msg.html

(cl:defclass <IntArray> (roslisp-msg-protocol:ros-message)
  ((deger
    :reader deger
    :initarg :deger
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0)))
)

(cl:defclass IntArray (<IntArray>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <IntArray>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'IntArray)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name projectx-msg:<IntArray> is deprecated: use projectx-msg:IntArray instead.")))

(cl:ensure-generic-function 'deger-val :lambda-list '(m))
(cl:defmethod deger-val ((m <IntArray>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader projectx-msg:deger-val is deprecated.  Use projectx-msg:deger instead.")
  (deger m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <IntArray>) ostream)
  "Serializes a message object of type '<IntArray>"
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'deger))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
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
   (cl:slot-value msg 'deger))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <IntArray>) istream)
  "Deserializes a message object of type '<IntArray>"
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'deger) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'deger)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616)))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<IntArray>)))
  "Returns string type for a message object of type '<IntArray>"
  "projectx/IntArray")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'IntArray)))
  "Returns string type for a message object of type 'IntArray"
  "projectx/IntArray")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<IntArray>)))
  "Returns md5sum for a message object of type '<IntArray>"
  "b33d02db9df612bb8d91e911852cbddb")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'IntArray)))
  "Returns md5sum for a message object of type 'IntArray"
  "b33d02db9df612bb8d91e911852cbddb")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<IntArray>)))
  "Returns full string definition for message of type '<IntArray>"
  (cl:format cl:nil "int64[] deger~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'IntArray)))
  "Returns full string definition for message of type 'IntArray"
  (cl:format cl:nil "int64[] deger~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <IntArray>))
  (cl:+ 0
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'deger) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <IntArray>))
  "Converts a ROS message object to a list"
  (cl:list 'IntArray
    (cl:cons ':deger (deger msg))
))
