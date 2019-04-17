//
//  PDChatManager.h
//  PDChatSDK
//
//  Created by PeiDou on 2019/3/19.
//  Copyright © 2019年 PeiDou. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PDError.h"

@interface PDChatManager : NSObject

+ (instancetype)shareManager;


/**
 C端登录服务器

 @param key 商家key
 @param visitSource 商家名字/项目名字
 @param customerAccount 客户账号
 @param customerNickname 客户昵称(非必传)
 @param customerHeadUrl 客户头像(非必传)
 @param viewController 当前控制器
 @param bundleId Bundle Identifier
 @param secretKey 秘钥
 @param pderror 错误信息
 */
+ (void)pdchatUserLoginWithBusinessKey:(NSString *)key
                       withVisitSource:(NSString *)visitSource
                   withCustomerAccount:(NSString *)customerAccount
                  withCustomerNickname:(NSString *)customerNickname
                   withCustomerHeadUrl:(NSString *)customerHeadUrl
             withCurrentViewController:(UIViewController *)viewController
                              bundleId:(NSString *)bundleId
                             secretKey:(NSString *)secretKey
                            errorBlock:(void(^)(PDError *error))pderror;


/**
 B端登录服务器

 @param loginAccount 登陆账号
 @param loginPwd 登录密码
 @param bundleId Bundle Identifier
 @param secretKey 秘钥
 @param pderror 错误信息
 */
+ (void)pdchatBusinessLoginWithBusinessAccount:(NSString *)loginAccount
                                      loginPwd:(NSString *)loginPwd
                                      bundleId:(NSString *)bundleId
                                     secretKey:(NSString *)secretKey
                                    errorBlock:(void(^)(PDError *error))pderror;


/**
 B端跳转到在线咨询列表

 @param viewController 当前控制
 */
+ (void)pdchatBussinessIntoOnlineConsultationByCurrentViewController:(UIViewController *)viewController;



/**
 APP进入后台

 @param application UIApplication
 */
+ (void)applicationDidEnterBackground:(UIApplication *)application;


/**
 APP将要从后台返回

 @param application UIApplication
 */
+ (void)applicationWillEnterForeground:(UIApplication *)application;

@end
