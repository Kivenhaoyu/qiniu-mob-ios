//
//  QNMobModel.h
//  QNMob
//
//  Created by 何昊宇 on 17/3/1.
//  Copyright © 2017年 Aaron. All rights reserved.
//

#import <AWSCore/AWSCore.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString *const QNMobErrorDomain;

typedef NS_ENUM(NSInteger, QNMobErrorType) {
    QNMobErrorUnknown,
    QNMobErrorFolderAlreadyExists,
    QNMobErrorFolderAlreadyOwnedByYou,
    QNMobErrorNoSuchFolder,
    QNMobErrorNoSuchFile,
};

@interface QNMobModel : AWSMTLModel

@end

/*
 * 用户登录数据
 */
@interface QNMobRegisterModel : NSObject

@property (nonatomic, strong) NSString * clientID;
@property (nonatomic, strong) NSString * accessToken;
@property (nonatomic, strong) NSString * refreshToken;

- (instancetype)initWithClientID:(NSString *)clientID
                     accessToken:(NSString *)accessToken
                    refreshToken:(NSString *)refreshToken;

@end

/*
 * 创建 folder 请求
 * @params folderPath string
 */
@interface QNMobCreateFolderRequest : AWSRequest
/**
 folder 目录，参数必须为绝对路径
 */
@property (nonatomic, strong) NSString * _Nullable folderPath;

@end

/*
 * 创建 folder 响应
 * @returns name string
 * @returns createTime timestamp
 * @returns modifyTime timestamp
 */
@interface QNMobCreateFolderOutput : AWSModel

/**
 folder名称
 */
@property (nonatomic, strong) NSString * _Nonnull name;

/**
 创建时间
 */
@property (nonatomic, strong) NSNumber * _Nonnull createTime;

/**
 修改时间
 */
@property (nonatomic, strong) NSNumber * _Nullable modifyTime;

@end


/**
 *检查 folder 请求
 */
@interface QNMobHeadFolderRequest : AWSRequest

/**
 folder 目录，参数必须为绝对路径
 */
@property (nonatomic, strong) NSString * _Nullable folderPath;

@end

/*
 * 检查 folder 响应
 * @returns name string
 * @returns createTime timestamp
 * @returns modifyTime timestamp
 */
@interface QNMobHeadFolderOutput : AWSModel

/**
 folder名称
 */
@property (nonatomic, strong) NSString * _Nonnull name;

/**
 授权令牌创建时间
 */
@property (nonatomic, strong) NSDate * _Nullable createTime;

/**
 授权令牌最后一次使用时间
 */
@property (nonatomic, strong) NSDate * _Nullable modifyTime;


@end

/**
 获取folder 请求
 */
@interface QNMobGetFolderRequest : AWSRequest
/**
 folder 目录，参数必须为绝对路径
 */
@property (nonatomic, strong) NSString * _Nullable folderPath;

@end

/**
 folder 信息
 */
@interface QNMobFolder : AWSModel

/**
 folder 名称
 */
@property (nonatomic, strong) NSString * _Nonnull name;

/**
 folder etag
 */
@property (nonatomic, strong) NSString * _Nonnull etag;

/**
 folder 为 0
 */
@property (nonatomic, strong) NSNumber * _Nullable size;

/**
equals to "" for folder
*/
@property (nonatomic, strong) NSString * _Nonnull mime;

/**
 folder 创建时间
 */
@property (nonatomic, strong) NSNumber * _Nullable createTime;

/**
 folder 最后修改时间
 */
@property (nonatomic, strong) NSNumber * _Nullable modifyTime;

@end

@interface QNMobContent : AWSModel

/**
 content 名称
 */
@property (nonatomic, strong) NSString * _Nonnull name;

/**
 content etag
 */
@property (nonatomic, strong) NSString * _Nonnull etag;

/**
 content 大小
 */
@property (nonatomic, strong) NSNumber * _Nullable size;

/**
 content 类型
 */
@property (nonatomic, strong) NSString * _Nonnull mime;

/**
 content 创建时间
 */
@property (nonatomic, strong) NSNumber * _Nullable createTime;

/**
 content 最后修改时间
 */
@property (nonatomic, strong) NSNumber * _Nullable modifyTime;

@end

/*
 * 获取 folder 响应
 */
@interface QNMobGetFolderOutput : AWSModel

/**
 A list of folder.
 */
@property (nonatomic, strong) NSArray<QNMobFolder *> * _Nullable folders;

/**
 A list of contents.
 */
@property (nonatomic, strong) NSArray<QNMobContent *> * _Nullable contents;

/**
 指定分页的对象名称 (object key)，服务器端只返回按字母序排序后指定对象名称以后的对象列表
 */
@property (nonatomic, strong) NSString * _Nonnull marker;

/**
 是下一页开始的分页 id
 */
@property (nonatomic, strong) NSString * _Nonnull nextMarker;

/**
 指定分页的最大返回对象数量，默认服务器端返回最多 1000 个对象；如果客户端需要控制返回对象的最大数量，可以通过指定该值实现
 */
@property (nonatomic, strong) NSNumber * _Nonnull maxKeys;

/**
  指定对象类型 (object mime)，其效果时只返回指定类型的对象
 */
@property (nonatomic, strong) NSString * _Nonnull contentType;

/**
 指定排序字段，支持按文件名 (name)，按文件修改时间 (mtime) 和按文件大小 (size) 排序，默认为按文件名
 */
@property (nonatomic, strong) NSString * _Nonnull sortBy;

/**
 排序类型，asc 或 desc，默认为 asc
 */
@property (nonatomic, strong) NSString * _Nonnull order;

/**
 仅返回文件夹
 */
@property (nonatomic, assign)  BOOL isFolder;

/**
 content 类型
 */
@property (nonatomic, assign) BOOL isTruncated;


@end


/**
 更新folder 请求
 */
@interface QNMobUpdateFolderRequest : AWSRequest

/**
 folder 目录，参数必须为绝对路径
 */
@property (nonatomic, strong) NSString * _Nullable folderPath;

/**
 // 必须为新文件夹的绝对路径，如 /DCIM/backup/20060102
 */
@property (nonatomic, strong) NSString * _Nullable rename;

@end

/*
 * 更新 folder 响应
 * @returns name string
 * @returns createTime timestamp
 * @returns modifyTime timestamp
 */
@interface QNMobUpdateFolderOutput : AWSModel

/**
 folder名称
 */
@property (nonatomic, strong) NSString * _Nonnull name;

/**
 创建时间
 */
@property (nonatomic, strong) NSNumber * _Nonnull createTime;

/**
 修改时间
 */
@property (nonatomic, strong) NSNumber * _Nullable modifyTime;

@end

/**
 删除folder
 */
@interface QNMobDeleteFolderRequest : AWSRequest

/**
 folder 目录，参数必须为绝对路径
 */
@property (nonatomic, strong) NSString * _Nullable folderPath;

/**
 *是否强制删除文件夹，不论文件夹内容是否为空
 */
@property (nonatomic, assign) BOOL deletionForce;

@end

/*
 * 创建 folder 请求
 * @params folderPath string
 */
@interface QNMobCreateFileRequest : AWSRequest

/**
 folder 目录，参数必须为绝对路径
 */
@property (nonatomic, strong) NSString * _Nullable filePath;

/**
 Object data.
 */
@property (nonatomic, strong) id _Nullable body;

/**
 Size of the body in bytes. This parameter is useful when the size of the body cannot be determined automatically.
 */
@property (nonatomic, strong) NSNumber * _Nullable contentLength;

/**
 The base64-encoded 128-bit MD5 digest of the part data.
 */
@property (nonatomic, strong) NSString * _Nullable contentMD5;

/**
 A standard MIME type describing the format of the object data.
 */
@property (nonatomic, strong) NSString * _Nullable contentType;

@end



/*
 * 更新 folder 响应
 * @returns name string
 * @returns createTime timestamp
 * @returns modifyTime timestamp
 */
@interface QNMobCreateFileOutput : AWSModel

/**
 file 名称
 */
@property (nonatomic, strong) NSString * _Nonnull name;

/**
 file etag
 */
@property (nonatomic, strong) NSString * _Nonnull etag;

/**
 file 大小
 */
@property (nonatomic, strong) NSNumber * _Nullable size;

/**
 file 类型
 */
@property (nonatomic, strong) NSString * _Nonnull mime;

/**
 file 创建时间
 */
@property (nonatomic, strong) NSNumber * _Nullable createTime;

/**
 file 最后修改时间
 */
@property (nonatomic, strong) NSNumber * _Nullable modifyTime;

@end

@interface QNMobHeadFileRequest : AWSRequest

/**
 file 目录，参数必须为绝对路径
 */
@property (nonatomic, strong) NSString * _Nullable filePath;

/**
 Return the file only if its entity tag (ETag) is the same as the one specified, otherwise return a 412 (precondition failed).
 */
@property (nonatomic, strong) NSString * _Nullable ifMatch;

/**
 Return the file only if it has been modified since the specified time, otherwise return a 304 (not modified).
 */
@property (nonatomic, strong) NSDate * _Nullable ifModifiedSince;

/**
 Return the file only if its entity tag (ETag) is different from the one specified, otherwise return a 304 (not modified).
 */
@property (nonatomic, strong) NSString * _Nullable ifNoneMatch;

/**
 Return the file only if it has not been modified since the specified time, otherwise return a 412 (precondition failed).
 */
@property (nonatomic, strong) NSDate * _Nullable ifUnmodifiedSince;

@end

@interface QNMobHeadFileOutput : AWSModel

/**
 Size of the body in bytes.
 */
@property (nonatomic, strong) NSNumber * _Nullable contentLength;

/**
 A standard MIME type describing the format of the file data.
 */
@property (nonatomic, strong) NSString * _Nullable contentType;

/**
 Last modified date of the file
 */
@property (nonatomic, strong) NSDate * _Nullable lastModified;

/**
 An ETag is an opaque identifier assigned by a web server to a specific version of a resource found at a URL
 */
@property (nonatomic, strong) NSString * _Nullable ETag;

@end

@interface QNMobGetFileRequest : AWSRequest

/**
 Return the object only if its entity tag (ETag) is the same as the one specified, otherwise return a 412 (precondition failed).
 */
@property (nonatomic, strong) NSString * _Nullable ifMatch;

/**
 Return the object only if it has been modified since the specified time, otherwise return a 304 (not modified).
 */
@property (nonatomic, strong) NSDate * _Nullable ifModifiedSince;

/**
 Return the object only if its entity tag (ETag) is different from the one specified, otherwise return a 304 (not modified).
 */
@property (nonatomic, strong) NSString * _Nullable ifNoneMatch;

/**
 Return the object only if it has not been modified since the specified time, otherwise return a 412 (precondition failed).
 */
@property (nonatomic, strong) NSDate * _Nullable ifUnmodifiedSince;

/**
 
 */
@property (nonatomic, strong) NSString * _Nullable filePath;

/**
 Sets the Cache-Control header of the response.
 */
@property (nonatomic, strong) NSString * _Nullable responseCacheControl;

/**
 Sets the Content-Disposition header of the response
 */
@property (nonatomic, strong) NSString * _Nullable responseContentDisposition;

/**
 Sets the Content-Type header of the response.
 */
@property (nonatomic, strong) NSString * _Nullable responseContentType;

/**
 Sets the Expires header of the response.
 */
@property (nonatomic, strong) NSDate * _Nullable responseExpires;

/**
 Downloads the specified range bytes of an object. For more information about the HTTP Range header
 */
@property (nonatomic, strong) NSString * _Nullable range;


@end

@interface QNMobGetFileOutput : AWSModel

/**
 Object data.
 */
@property (nonatomic, strong) id _Nullable body;

/**
 Size of the body in bytes.
 */
@property (nonatomic, strong) NSNumber * _Nullable contentLength;

/**
 The portion of the object returned in the response.
 */
@property (nonatomic, strong) NSString * _Nullable contentRange;

/**
 A standard MIME type describing the format of the object data.
 */
@property (nonatomic, strong) NSString * _Nullable contentType;


/**
 An ETag is an opaque identifier assigned by a web server to a specific version of a resource found at a URL
 */
@property (nonatomic, strong) NSString * _Nullable ETag;

@end

@interface QNMobCopyFileRequest : AWSRequest

/**
 The name of the source bucket and key name of the source object, separated by a slash (/). Must be URL-encoded.
 */
@property (nonatomic, strong) NSString * _Nullable copiedSource;

/**
 Copies the object if its entity tag (ETag) matches the specified tag.
 */
@property (nonatomic, strong) NSString * _Nullable copiedSourceIfMatch;

/**
 Copies the object if it has been modified since the specified time.
 */
@property (nonatomic, strong) NSDate * _Nullable copiedSourceIfModifiedSince;

/**
 Copies the object if its entity tag (ETag) is different than the specified ETag.
 */
@property (nonatomic, strong) NSString * _Nullable copiedSourceIfNoneMatch;

/**
 Copies the object if it hasn't been modified since the specified time.
 */
@property (nonatomic, strong) NSDate * _Nullable copiedSourceIfUnmodifiedSince;

/**
 
 */
@property (nonatomic, strong) NSString * _Nullable filePath;

/**
 Downloads the specified range bytes of an object. For more information about the HTTP Range header
 */
@property (nonatomic, strong) NSString * _Nullable range;

@end

@interface QNMobCopyFileOutput : AWSModel

/**
 file 名称
 */
@property (nonatomic, strong) NSString * _Nonnull name;

/**
 file etag
 */
@property (nonatomic, strong) NSString * _Nonnull etag;

/**
 file 大小
 */
@property (nonatomic, strong) NSNumber * _Nullable size;

/**
 file 类型
 */
@property (nonatomic, strong) NSString * _Nonnull mime;

/**
 file 创建时间
 */
@property (nonatomic, strong) NSNumber * _Nullable createTime;

/**
 file 最后修改时间
 */
@property (nonatomic, strong) NSNumber * _Nullable modifyTime;


@end

@interface QNMobDeleteFileRequest : AWSRequest

/**
 file 目录，参数必须为绝对路径
 */
@property (nonatomic, strong) NSString * _Nullable filePath;

/**
 Return the file only if its entity tag (ETag) is the same as the one specified, otherwise return a 412 (precondition failed).
 */
@property (nonatomic, strong) NSString * _Nullable ifMatch;

/**
 Return the file only if it has been modified since the specified time, otherwise return a 304 (not modified).
 */
@property (nonatomic, strong) NSDate * _Nullable ifModifiedSince;

/**
 Return the file only if its entity tag (ETag) is different from the one specified, otherwise return a 304 (not modified).
 */
@property (nonatomic, strong) NSString * _Nullable ifNoneMatch;

/**
 Return the file only if it has not been modified since the specified time, otherwise return a 412 (precondition failed).
 */
@property (nonatomic, strong) NSDate * _Nullable ifUnmodifiedSince;

@end

@interface QNMobDeleteFileObject : AWSModel
/**
 file 名称
 */
@property (nonatomic, strong) NSString * _Nonnull name;

@end

@interface QNMobDeleteFileFailObject : AWSModel
/**
 file 名称
 */
@property (nonatomic, strong) NSString * _Nonnull name;

/**
 
 */
@property (nonatomic, strong) NSString * _Nonnull message;

@end

@interface QNMobRemove : AWSModel

/**
 
 */
@property (nonatomic, strong) NSArray<QNMobDeleteFileObject *> * _Nullable objects;

/**
 Element to enable quiet mode for the request. When you add this element, you must set its value to true.
 */
@property (nonatomic, assign) BOOL quiet;

@end

@interface QNMobDeleteFilesRequest : AWSRequest

/**
请求体长度，单位为 byte
 */
@property (nonatomic, strong) NSNumber * _Nullable contentLength;

/**
Base64 编码的请求体 MD5 摘要值
 */
@property (nonatomic, strong) NSString * _Nullable contentMD5;

/**
 
 */
@property (nonatomic, strong) QNMobRemove * _Nullable remove;

@end

@interface QNMobDeleteFilesOutput : AWSModel

/**
 
 */
@property (nonatomic, strong) NSArray<QNMobDeleteFileObject *> * _Nullable deleted;

/**
 
 */
@property (nonatomic, strong) NSArray<QNMobDeleteFileFailObject *> * _Nullable errors;

@end


NS_ASSUME_NONNULL_END


