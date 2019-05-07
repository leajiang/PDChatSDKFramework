//
//  PDChatManager.h
//  PDChatSDK
//
//  Created by PeiDou on 2019/3/19.
//  Copyright © 2019年 PeiDou. All rights reserved.
//

//#1.标记tag
//#2.配置文件
//#3.创建账号 pod trunk register 邮箱 联系人 --description="描述" --verbose
//#4.验证
//#5.提交pod trunk push

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PDChatError.h"

@interface PDChatManager : NSObject

+ (instancetype)shareManager;

/**
 胚豆SDK申请的应用key
 */
@property(copy,nonatomic)NSString * secretKey;
/**
 高德地图申请的key（如不传则聊天不能发送当前位置）
 */
@property(copy,nonatomic)NSString * lbsAmapKey;

/**
 C端登录服务器

 @param businessKey 商家key
 @param visitSource 商家名字/项目名字
 @param customerAccount 客户账号
 @param customerNickname 客户昵称(非必传)
 @param customerHeadUrl 客户头像(非必传)
 @param viewController 当前控制器
 @param pderror 错误信息
 */
- (void)pdchatUserLoginWithBusinessKey:(NSString *)businessKey
                       withVisitSource:(NSString *)visitSource
                   withCustomerAccount:(NSString *)customerAccount
                  withCustomerNickname:(NSString *)customerNickname
                   withCustomerHeadUrl:(NSString *)customerHeadUrl
             withCurrentViewController:(UIViewController *)viewController
                            errorBlock:(void(^)(PDChatError *error))pderror;


/**
 B端登录服务器

 @param loginAccount 登陆账号
 @param loginPwd 登录密码
 @param pderror 错误信息
 */
- (void)pdchatBusinessLoginWithBusinessAccount:(NSString *)loginAccount
                                      loginPwd:(NSString *)loginPwd
                                    errorBlock:(void(^)(PDChatError *error))pderror;


/**
 B端跳转到在线咨询列表

 @param viewController 当前控制器
 */
- (void)pdchatBussinessIntoOnlineConsultationByCurrentViewController:(UIViewController *)viewController;



/**
 APP进入后台

 @param application UIApplication
 */
- (void)applicationDidEnterBackground:(UIApplication *)application;


/**
 APP将要从后台返回

 @param application UIApplication
 */
- (void)applicationWillEnterForeground:(UIApplication *)application;

@end
