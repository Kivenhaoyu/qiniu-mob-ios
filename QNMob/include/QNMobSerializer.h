//
//  QNMobSerializer.h
//  QNMob
//
//  Created by 何昊宇 on 17/3/4.
//  Copyright © 2017年 Aaron. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AWSCore/AWSCore.h>

@interface QNMobRequestSerializer : NSObject<AWSURLRequestSerializer>

- (instancetype)initWithJSONDefinition:(NSDictionary *)JSONDefinition
                            actionName:(NSString *)actionName;

@end

@interface QNMobResponseSerializer : NSObject <AWSHTTPURLResponseSerializer>

@property (nonatomic, assign) Class outputClass;

- (instancetype)initWithJSONDefinition:(NSDictionary *)JSONDefinition
                            actionName:(NSString *)actionName
                           outputClass:(Class)outputClass;

@end
