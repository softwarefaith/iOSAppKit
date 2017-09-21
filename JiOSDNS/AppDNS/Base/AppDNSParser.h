//
//  AppHostParser.h
//  JiOSDNS
//
//  Created by 蔡杰 on 2017/9/6.
//  Copyright © 2017年 蔡杰. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 
 通过网络解析
 
 案例:
 //1.解析 www.163.com&ttl=1  //111.206.186.244;111.206.186.245,23  其中23是ttl缓存时间
 //2.www.baidu.com  :  61.135.169.125;61.135.169.121   没有ttl
 
 */

typedef void(^AppHostParserCallback)(NSArray *ips,id extra,NSError *error);


@interface AppHostParser : NSObject

///syn get ip, will block the thread
+ (NSArray *) ipSynParseWithHost:(NSString*)host;
///asyn get ip
+ (void)ipAsynParseWithHost:(NSString*)host withComplete:(AppHostParserCallback)hostCallback;
@end