//
//  PDError.h
//  PDChatSDK
//
//  Created by PeiDou on 2019/2/28.
//  Copyright © 2019年 PeiDou. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    PDErrorServerTimeout = 1,   //超时
    PDErrorServerConnectFail,   //连接失败
    PDErrorServerNotReachable,  //服务未连接
    PDErrorInvalidUsername,     //用户名无效
    PDErrorSASLAuthenticationFailed,     //登录认证失败
    PDErrorNetworkUnavailable,  //网络不可用
    
    PDErrorRequestFail,    //请求服务器失败
    PDErrorOauthtoken,    //授权失败
    PDErrorSelectBusinessByKey, //根据商家秘钥获取商家信息失败
    PDErrorAddCustomerVisit,    //新增访问信息失败
    PDErrorStartSession,    //发起会话失败
    
    
} PDErrorCode;

@interface PDError : NSObject

@property (nonatomic) PDErrorCode code;
@property (nonatomic, copy) NSString *errorDescription;
- (instancetype)initWithDescription:(NSString *)aDescription
                               code:(PDErrorCode)aCode;
@end
