//
//  QNMobEnum.h
//  QNMob
//
//  Created by 何昊宇 on 17/3/2.
//  Copyright © 2017年 Aaron. All rights reserved.
//

#ifndef QNMobEnum_h
#define QNMobEnum_h

/**
 *  Enums for QN regions.
 *
 */
typedef NS_ENUM(NSInteger, QNRegionType) {
    /**
     *  Unknown Region
     */
    QNMobRegionUnknown NS_SWIFT_NAME(Unknown),
    
    /**
     *  华北
     */
    QNMobRegionCNNorth1 NS_SWIFT_NAME(CNMobNorth1),
    
    /**
     *  华东
     */
    QNMobRegionCNEast1 NS_SWIFT_NAME(CNMobEast1),
    
    /**
     *  华南
     */
    QNMobRegionCNSouth1 NS_SWIFT_NAME(CNMobSouth1),
};
#endif /* QNMobEnum_h */
