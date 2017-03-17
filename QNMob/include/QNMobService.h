//
//  QNMobService.h
//  QNMob
//
//  Created by 何昊宇 on 17/3/3.
//  Copyright © 2017年 Aaron. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "QNMob.h"

NS_ASSUME_NONNULL_BEGIN

@interface QNMob : NSObject

+ (instancetype) defaultQNMob;

- (void)createFolder:(QNMobCreateFolderRequest *)request completionHandler:(void (^ _Nullable)(QNMobCreateFolderOutput * _Nullable response, NSError * _Nullable error))completionHandler;

- (void)headFolder:(QNMobHeadFolderRequest *)request completionHandler:(void (^ _Nullable)(QNMobHeadFolderOutput * _Nullable response, NSError * _Nullable error))completionHandler;

- (void)getMobFolder:(QNMobGetFolderRequest *)request completionHandler:(void (^ _Nullable)(QNMobGetFolderOutput * _Nullable response, NSError * _Nullable error))completionHandler;

- (void)updateFolder:(QNMobUpdateFolderRequest *)request completionHandler:(void (^ _Nullable)(QNMobUpdateFolderOutput * _Nullable response, NSError * _Nullable error))completionHandler;

- (void)deleteFolder:(QNMobDeleteFolderRequest *)request completionHandler:(void (^)(NSError *error))completionHandler;

- (void)createFile:(QNMobCreateFileRequest *)request completionHandler:(void (^ _Nullable)(QNMobCreateFileOutput * _Nullable response, NSError * _Nullable error))completionHandler;

- (void)headFile:(QNMobHeadFileRequest *)request completionHandler:(void (^ _Nullable)(QNMobHeadFileOutput * _Nullable response, NSError * _Nullable error))completionHandler;

- (void)getFile:(QNMobGetFileRequest *)request
completionHandler:(void (^)(QNMobGetFileOutput *response, NSError *error))completionHandler;

- (void)copyFile:(QNMobCopyFileRequest *)request
completionHandler:(void (^)(QNMobCopyFileOutput *response, NSError *error))completionHandler;

- (void)deleteFile:(QNMobDeleteFileRequest *)request completionHandler:(void (^)(NSError *error))completionHandler;

- (void)deleteFiles:(QNMobDeleteFilesRequest *)request completionHandler:(void (^ _Nullable)(QNMobDeleteFilesOutput * _Nullable response, NSError * _Nullable error))completionHandler;
@end

NS_ASSUME_NONNULL_END
