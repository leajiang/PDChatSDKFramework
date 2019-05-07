//
//  PDChatConversationModel.h
//  PDChatSDK
//
//  Created by PeiDou on 2019/4/25.
//  Copyright © 2019年 PeiDou. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PDChatMessageModel.h"

@interface PDChatConversationModel : NSObject
@property(nonatomic,copy) NSString *id;
@property(nonatomic,copy) NSString *conversationId;
@property(assign,nonatomic)NSInteger sessionType;
@property(nonatomic,copy) NSString *visitId;
@property(assign,nonatomic)NSInteger lineStatus;
@property(nonatomic,copy) NSString *tenantId;
@property(nonatomic,copy) NSString *csCenterName;
@property(assign,nonatomic)NSInteger deviceType;
@property(nonatomic,copy) NSString *customerId;
@property(nonatomic,copy) NSString *createTime;
@property(assign,nonatomic)NSInteger accessChannel;
@property(nonatomic,copy) NSString *nickName;
@property(nonatomic,copy) NSString *sessionId;
@property(assign,nonatomic)NSInteger chatType;
@property(assign,nonatomic)NSInteger isIcon;
@property(nonatomic,copy) NSString *businessId;
@property(nonatomic,copy) NSString *customerLevel;
@property(assign,nonatomic)NSInteger followFlag;

@property(nonatomic, assign) PDMessageChatType chat_type;
@property(nonatomic, strong) PDChatMessageModel *latestMessage;
@property(assign,nonatomic)NSInteger unreadCount;
- (instancetype)initWithConversationId:(NSString *)conversationId
                          withChatType:(PDMessageChatType)chatType
                              withTime:(NSString *)time;
@end


