//
//  PDChatMessageManager.h
//  PDChatSDK
//
//  Created by PeiDou on 2019/4/17.
//  Copyright © 2019年 PeiDou. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PDChatConversationModel.h"
#import "PDChatMessageModel.h"

@protocol PDChatMessageManagerDelegate <NSObject>

@optional

/**
 获取到PDChatMessageModel消息 上层通讯业务处理
 
 @param message PDChatMessageModel
 */
-(void)didReceiveMessage:(PDChatMessageModel *)message;

/**
 当前未读消息条数的实时回调
 
 @param count 未读条数
 */
- (void)pdChatUnreadmessageCount:(NSInteger)count;

/**
 某条消息发送状态改变时回调
 
 @param msgId id
 @param status 发送状态
 */
-(void)updateMessage:(NSString *)msgId sendStatus:(PDMessageSendStatus)status;

/**
 当前登录账号被强制退出时会收到该回调
 */
- (void)userAccountDidForcedToLogout:(NSString *)msg;

/**
 业务功能处理
 
 @param businesscode 业务处理code
 */
- (void)businessOperation:(NSInteger)businesscode;

@end

@interface PDChatMessageManager : NSObject

@property(weak,nonatomic)id<PDChatMessageManagerDelegate> delegate;

+ (instancetype)shareManager;

/**
 获取文字消息模型
 
 @param content 内容
 @param to 接受者
 @param messageType 单聊/群聊
 @return PDChatMessageModel
 */
-(PDChatMessageModel *)getTextMessageByText:(NSString *)content
                                     to:(NSString *)to
                                    ext:(NSString *)ext
                        messageChatType:(PDMessageChatType)messageType;

/**
 获取图片消息模型
 
 @param remoteFilePath 远程地址
 @param thumbnailFilePath 缩略图地址
 @param image 图片
 @param to 接受者
 @param messageType messageType 单聊/群聊
 @return PDChatMessageModel
 */
-(PDChatMessageModel *)getImageMessageByRemoteFilePath:(NSString *)remoteFilePath
                                 thumbnailFilePath:(NSString *)thumbnailFilePath
                                             image:(UIImage *)image
                                                to:(NSString *)to
                                               ext:(NSString *)ext
                                   messageChatType:(PDMessageChatType)messageType;



/**
 获取语音消息模型
 
 @param remoteFilePath 远程地址
 @param duration 播放时间
 @param to 接收者
 @param messageType 单聊/群聊
 @return PDChatMessageModel
 */
-(PDChatMessageModel *)getAudioMessageByRemoteFilePath:(NSString *)remoteFilePath
                                          duration:(NSInteger)duration
                                                to:(NSString *)to
                                               ext:(NSString *)ext
                                   messageChatType:(PDMessageChatType)messageType;


/**
 获取地图消息模型
 
 @param longitude 经度
 @param latitude 纬度
 @param address 地址
 @param to 接收者
 @param messageType 单聊/群聊
 @return PDChatMessageModel
 */
-(PDChatMessageModel *)getMapMessageBylongitude:(CGFloat)longitude
                                   latitude:(CGFloat)latitude
                                    address:(NSString *)address
                                         to:(NSString *)to
                                        ext:(NSString *)ext
                            messageChatType:(PDMessageChatType)messageType;


/**
 获取商品消息模型
 
 @param name 商品名字
 @param price 商品价格
 @param imgUrl 商品图片url
 @param commodityUrl 商品链接
 @param messageType messageType 单聊/群聊
 @param to 接收者
 @return PDChatMessageModel
 */
-(PDChatMessageModel *)getGoodsMessageBygoodsname:(NSString *)name
                                        price:(NSString *)price
                                       imgUrl:(NSString *)imgUrl
                                 commodityUrl:(NSString *)commodityUrl
                                           to:(NSString *)to
                                          ext:(NSString *)ext
                              messageChatType:(PDMessageChatType)messageType;

/**
 发送消息 异步方法（包含了saveMessage与sendPackage方法）
 
 @param message PDChatMessageModel
 */
-(void)sendMessage:(PDChatMessageModel *)message;


/**
 存储消息
 
 @param message PDChatMessageModel
 */
-(void)saveMessage:(PDChatMessageModel *)message;


/**
 发送协议包
 
 @param message PDChatMessageModel
 */
-(void)sendPackage:(PDChatMessageModel *)message;

/**
 获取所有的会话列表数据 异步方法
 
 */
-(void)getAllConversation:(void(^)(NSMutableArray <PDChatConversationModel *>* conversations))finishBlock;

/**
 根据会话id获取聊天数据 异步方法
 
 @param conversationId 会话ID
 @param message 传入的messag后面的10条 分页用 第一次请求则传nil
 */
-(void)loadMessagesWithConversationId:(NSString *)conversationId
                        pagingMessage:(PDChatMessageModel *)message
                               finish:(void(^)(NSMutableArray <PDChatMessageModel *>* messages))finishBlock;

/**
 根据会话id获取聊天数据 异步方法
 
 @param businessId 商家ID
 @param message 传入的messag后面的10条 分页用 第一次请求则传nil
 */
-(void)loadMessagesWithBusinessId:(NSString *)businessId
                    pagingMessage:(PDChatMessageModel *)message
                           finish:(void(^)(NSMutableArray <PDChatMessageModel *>* messages))finishBlock;

/**
 根据会话id获取会话 同步方法
 
 @param conversationid 会话id
 @return 会话模型
 */
-(PDChatConversationModel *)loadConversationWithConversationid:(NSString *)conversationid;

/**
 更新已读或未读状态
 
 @param conversationId 会话id
 @param ifag 0/1  未读/已读
 */
-(void)updateMessage:(NSString *)conversationId isRead:(NSInteger)ifag finish:(void(^)(BOOL res))finishBlock;

/**
 更新消息发送状态
 
 @param msgId 消息id
 @param status PDMessageSendStatus 枚举
 @param finishBlock 成功/失败
 */
-(void)updateMessage:(NSString *)msgId sendStatus:(PDMessageSendStatus)status finish:(void(^)(BOOL res))finishBlock;

/**
 重新发送消息（消息状态为正在发送中）
 */
-(void)againSendMessageByStatusSending;

/**
 消息业务逻辑处理

 @param message id
 */
-(void)didReceiveMessage:(id)message;
@end

