; Auto-generated. Do not edit!


(cl:in-package touchosc_msgs-msg)


;//! \htmlinclude CommonProperties.msg.html

(cl:defclass <CommonProperties> (roslisp-msg-protocol:ros-message)
  ((tabpage
    :reader tabpage
    :initarg :tabpage
    :type cl:string
    :initform "")
   (name
    :reader name
    :initarg :name
    :type cl:string
    :initform "")
   (x
    :reader x
    :initarg :x
    :type cl:fixnum
    :initform 0)
   (y
    :reader y
    :initarg :y
    :type cl:fixnum
    :initform 0)
   (width
    :reader width
    :initarg :width
    :type cl:fixnum
    :initform 0)
   (height
    :reader height
    :initarg :height
    :type cl:fixnum
    :initform 0)
   (visible
    :reader visible
    :initarg :visible
    :type cl:string
    :initform "")
   (color
    :reader color
    :initarg :color
    :type cl:string
    :initform ""))
)

(cl:defclass CommonProperties (<CommonProperties>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <CommonProperties>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'CommonProperties)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name touchosc_msgs-msg:<CommonProperties> is deprecated: use touchosc_msgs-msg:CommonProperties instead.")))

(cl:ensure-generic-function 'tabpage-val :lambda-list '(m))
(cl:defmethod tabpage-val ((m <CommonProperties>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader touchosc_msgs-msg:tabpage-val is deprecated.  Use touchosc_msgs-msg:tabpage instead.")
  (tabpage m))

(cl:ensure-generic-function 'name-val :lambda-list '(m))
(cl:defmethod name-val ((m <CommonProperties>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader touchosc_msgs-msg:name-val is deprecated.  Use touchosc_msgs-msg:name instead.")
  (name m))

(cl:ensure-generic-function 'x-val :lambda-list '(m))
(cl:defmethod x-val ((m <CommonProperties>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader touchosc_msgs-msg:x-val is deprecated.  Use touchosc_msgs-msg:x instead.")
  (x m))

(cl:ensure-generic-function 'y-val :lambda-list '(m))
(cl:defmethod y-val ((m <CommonProperties>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader touchosc_msgs-msg:y-val is deprecated.  Use touchosc_msgs-msg:y instead.")
  (y m))

(cl:ensure-generic-function 'width-val :lambda-list '(m))
(cl:defmethod width-val ((m <CommonProperties>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader touchosc_msgs-msg:width-val is deprecated.  Use touchosc_msgs-msg:width instead.")
  (width m))

(cl:ensure-generic-function 'height-val :lambda-list '(m))
(cl:defmethod height-val ((m <CommonProperties>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader touchosc_msgs-msg:height-val is deprecated.  Use touchosc_msgs-msg:height instead.")
  (height m))

(cl:ensure-generic-function 'visible-val :lambda-list '(m))
(cl:defmethod visible-val ((m <CommonProperties>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader touchosc_msgs-msg:visible-val is deprecated.  Use touchosc_msgs-msg:visible instead.")
  (visible m))

(cl:ensure-generic-function 'color-val :lambda-list '(m))
(cl:defmethod color-val ((m <CommonProperties>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader touchosc_msgs-msg:color-val is deprecated.  Use touchosc_msgs-msg:color instead.")
  (color m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <CommonProperties>) ostream)
  "Serializes a message object of type '<CommonProperties>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'tabpage))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'tabpage))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'name))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'name))
  (cl:let* ((signed (cl:slot-value msg 'x)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'y)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'width)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'width)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'height)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'height)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'visible))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'visible))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'color))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'color))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <CommonProperties>) istream)
  "Deserializes a message object of type '<CommonProperties>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'tabpage) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'tabpage) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'name) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'name) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'x) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'y) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'width)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'width)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'height)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'height)) (cl:read-byte istream))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'visible) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'visible) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'color) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'color) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<CommonProperties>)))
  "Returns string type for a message object of type '<CommonProperties>"
  "touchosc_msgs/CommonProperties")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'CommonProperties)))
  "Returns string type for a message object of type 'CommonProperties"
  "touchosc_msgs/CommonProperties")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<CommonProperties>)))
  "Returns md5sum for a message object of type '<CommonProperties>"
  "2c6057f4de35b509307640ef1d0f3aac")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'CommonProperties)))
  "Returns md5sum for a message object of type 'CommonProperties"
  "2c6057f4de35b509307640ef1d0f3aac")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<CommonProperties>)))
  "Returns full string definition for message of type '<CommonProperties>"
  (cl:format cl:nil "# Common functionality to all TouchOSC controls~%~%string tabpage          # Control tabpage~%string name             # Control Name~%int16 x                 # X position of the control~%int16 y                 # Y position of the control~%uint16 width            # Width of the control~%uint16 height           # Height of the control~%string visible          # Visibility of the control~%~%# Possible colors are:~%# \"red\", \"green\", \"blue\", \"yellow\", \"orange\", \"purple\", \"gray\"~%string color            # Color of the control~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'CommonProperties)))
  "Returns full string definition for message of type 'CommonProperties"
  (cl:format cl:nil "# Common functionality to all TouchOSC controls~%~%string tabpage          # Control tabpage~%string name             # Control Name~%int16 x                 # X position of the control~%int16 y                 # Y position of the control~%uint16 width            # Width of the control~%uint16 height           # Height of the control~%string visible          # Visibility of the control~%~%# Possible colors are:~%# \"red\", \"green\", \"blue\", \"yellow\", \"orange\", \"purple\", \"gray\"~%string color            # Color of the control~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <CommonProperties>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'tabpage))
     4 (cl:length (cl:slot-value msg 'name))
     2
     2
     2
     2
     4 (cl:length (cl:slot-value msg 'visible))
     4 (cl:length (cl:slot-value msg 'color))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <CommonProperties>))
  "Converts a ROS message object to a list"
  (cl:list 'CommonProperties
    (cl:cons ':tabpage (tabpage msg))
    (cl:cons ':name (name msg))
    (cl:cons ':x (x msg))
    (cl:cons ':y (y msg))
    (cl:cons ':width (width msg))
    (cl:cons ':height (height msg))
    (cl:cons ':visible (visible msg))
    (cl:cons ':color (color msg))
))
