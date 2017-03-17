//
//  QNMobAPI.h
//  QNMob
//
//  Created by 何昊宇 on 17/3/2.
//  Copyright © 2017年 Aaron. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QNMob.h"
#import "QNMobEnum.h"

@interface QNMobAPI : NSObject

+ (void)registerWithMobRegisterModel:(QNMobRegisterModel *) registerModel;

+ (void)registerWithMobRegisterModel:(QNMobRegisterModel *) registerModel
                          regionType:(QNRegionType)regionType;

@end
