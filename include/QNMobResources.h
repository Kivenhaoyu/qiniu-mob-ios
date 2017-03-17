//
//  QNMobResources.h
//  QNMob
//
//  Created by 何昊宇 on 17/3/4.
//  Copyright © 2017年 Aaron. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface QNMobResources : NSObject

+ (instancetype)sharedInstance;

- (NSDictionary *)JSONObject;

@end
