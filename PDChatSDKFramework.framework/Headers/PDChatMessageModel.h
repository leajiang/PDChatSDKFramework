//
//  PDChatMessageModel.h
//  PDChatSDK
//
//  Created by PeiDou on 2019/4/25.
//  Copyright © 2019年 PeiDou. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UIKit/UIKit.h"
#import "PDChatUser.h"

typedef enum : NSUInteger {
    PDMessageTypeText = 1,
    PDMessageTypeImage,
    PDMessageTypeVideo,
    PDMessageTypeLocal,
    PDMessageTypeAudio,
    PDMessageTypeFile,
    PDMessageTypeCmd,
    PDMessageTypeHtml,
    PDMessageTypeJson,
    PDMessageTypeNotice,
} PDMessageType;

typedef enum : NSUInteger {
    PDMessageChatTypeChat = 1,
    PDMessageChatTypeGroupChat,
} PDMessageChatType;

typedef enum : NSUInteger {
    PDMessageSendStatusSending = 0,
    PDMessageSendStatusSendSuccess,
    PDMessageSendStatusSendError,
} PDMessageSendStatus;


typedef enum :NSUInteger{
    PDMessageDirectionSend = 0,
    PDMessageDirectionReceive,
} PDMessageDirection;

@interface PDChatMessageModel : NSObject

/**
 业务相关tenant_id
 */
@property(assign,nonatomic)NSInteger tenant_id;

/**
 业务相关business_id
 */
@property(copy,nonatomic)NSString *business_id;

/**
 业务相关session_id
 */
@property(assign,nonatomic)NSInteger session_id;

/**
 消息主键
 */
@property(assign,nonatomic)NSInteger id;

/**
 时间（毫秒）
 */
@property(copy,nonatomic)NSString *send_time;

/**
 消息类型
 */
@property(assign,nonatomic)PDMessageType msg_type;

/**
 发送者
 */
@property(strong,nonatomic)PDChatUser *msg_sender;

/**
 接收者
 */
@property(strong,nonatomic)PDChatUser *msg_receiver;

/**
 消息内容
 */
@property(copy,nonatomic)NSString *msg_content;

/**
 类型（单聊/群聊）
 */
@property(assign,nonatomic)PDMessageChatType chat_type;

/**
 生成的消息ID
 */
@property(copy,nonatomic)NSString * im_msg_id;

/**
 消息属于的会话ID
 */
@property(copy,nonatomic)NSString * conversationId;

/**
 是否已读
 */
@property(assign,nonatomic)NSInteger isRead;

/**
 消息发送状态
 */
@property(assign,nonatomic)PDMessageSendStatus msg_send_status;

/**
 消息的方向（自己发送/接收）
 */
@property(assign,nonatomic)PDMessageDirection direction;

/**
 拓展字段（json字符串）
 */
@property(copy,nonatomic)NSString *ext;

/**
 拓展字段（非必须）
 */
@property(strong,nonatomic)NSDictionary *config;

- (instancetype)initWithContent:(NSString *)content
                             to:(NSString *)to
                            ext:(NSString *)ext
                    messageType:(PDMessageType)messageType
                messageChatType:(PDMessageChatType)messageChatType;

/**
 消息转Element
 
 @return Element
 */
- (id)getMessageElement;


/**
 obj转PDChatMessageModel
 
 @param obj 消息字典
 @param flagid 会话ID
 @return PDChatMessageModel
 */
+ (PDChatMessageModel *)getMessageBymsgSource:(NSDictionary *)obj flagid:(NSString *)flagid;
@end
