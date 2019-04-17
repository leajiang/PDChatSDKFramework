//
//  PDMessageModel.h
//  PDChatSDK
//
//  Created by PeiDou on 2019/2/18.
//  Copyright © 2019年 PeiDou. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UIKit/UIKit.h"
#import "PDChatUser.h"

typedef enum : NSUInteger {
    PDMessageTypeText = 1,
    PDMessageTypeImage = 2,
    PDMessageTypeVideo = 3,
    PDMessageTypeLocal = 4,
    PDMessageTypeAudio = 5,
    PDMessageTypeFile = 6,
    PDMessageTypeCmd = 7,
    PDMessageTypeHtml = 8,
    PDMessageTypeJson = 9,
    PDMessageTypeNotice = 10,
} PDMessageType;


typedef enum : NSUInteger {
    PDMessageChatTypeChat = 1,
    PDMessageChatTypeGroupChat,
} PDMessageChatType;

typedef enum : NSUInteger {
    PDMessageSendStatusSending,
    PDMessageSendStatusSendSuccess,
    PDMessageSendStatusSendError,
} PDMessageSendStatus;

typedef enum :NSUInteger{
    PDMessageDirectionSend = 0,    /*! \~chinese 发送的消息 \~english Send */
    PDMessageDirectionReceive,     /*! \~chinese 接收的消息 \~english Receive */
} PDMessageDirection;

@interface PDMessageModel : NSObject

@property(assign,nonatomic)NSInteger tenant_id;
@property(copy,nonatomic)NSString *business_id;
@property(assign,nonatomic)NSInteger session_id;

@property(assign,nonatomic)NSInteger id;            //消息主键
@property(copy,nonatomic)NSString *send_time;       //毫秒
@property(assign,nonatomic)PDMessageType msg_type;  //消息类型
@property(strong,nonatomic)PDChatUser *msg_sender;
@property(strong,nonatomic)PDChatUser *msg_receiver;
@property(copy,nonatomic)NSString *msg_content;
@property(assign,nonatomic)PDMessageChatType chat_type;  //类型
@property(copy,nonatomic)NSString * im_msg_id;
@property(copy,nonatomic)NSString * conversationId;     //会话ID
@property(assign,nonatomic)NSInteger isRead;            //是否已读
@property(assign,nonatomic)PDMessageSendStatus msg_send_status; //消息状态
@property(assign,nonatomic)PDMessageDirection direction; //消息的方向
@property(copy,nonatomic)NSString *ext;     //拓展字段（json字符串）
@property(strong,nonatomic)NSDictionary *config;     //非必须

- (instancetype)initWithContent:(NSString *)content
                             to:(NSString *)to
                            ext:(NSString *)ext
                    messageType:(PDMessageType)messageType
                messageChatType:(PDMessageChatType)messageChatType;

- (id)getMessageElement;

+ (PDMessageModel *)getMessageBymsgSource:(NSDictionary *)obj flagid:(NSString *)flagid;
@end
