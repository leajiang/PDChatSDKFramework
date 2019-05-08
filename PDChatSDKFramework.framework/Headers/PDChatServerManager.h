//
//  PDChatServerManager.h
//  PDChatSDK
//
//  Created by PeiDou on 2019/4/17.
//  Copyright © 2019年 PeiDou. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PDChatError.h"

@interface PDChatServerManager : NSObject

+ (instancetype)shareManager;

/**
 当前连接状态
 */
@property(assign,nonatomic)BOOL PDChatConnected;

/**
 连接服务器
 
 @param imAccount IM 账号
 @param imPassword IM 密码
 @param aCompletionBlock PDError
 */
- (void)connectServerByimAccount:(NSString *)imAccount
                  withimPassword:(NSString *)imPassword
                      completion:(void (^)(PDChatError *aError))aCompletionBlock;


/**
 上线
 */
- (void)online;

/**
 离线
 */
- (void)offline;

/**
 注销
 */
- (void)logout;

/**
 发送消息
 
 @param xmlElement NSXMLElement
 */
- (void)sendMessage:(id)xmlElement;

@end
