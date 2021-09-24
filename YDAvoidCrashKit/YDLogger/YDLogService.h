//
//  YDLogService.h
//  YDKitDemo
//
//  Created by wangyuandong on 2021/9/22.
//

#import <Foundation/Foundation.h>
#import "YDMmapLogService.h"
NS_ASSUME_NONNULL_BEGIN
/**
 日志记录宏，只记录到本地，使用方法和NSLog相同，引用当前文件后可直接使用
 根据日志level的不同，记录的日志不同
 当调用setLogLevel:设置需要记录的日志level为YDLogDebug时，那么YDLogDebug等级以下的等级（含YDLogDebug）都会被记录
 默认设置为YDLogDetail
 
 YDLogError()   记录错误信息，适用于线上/线下环境，格式：@"Erro timeStamp error"
 YDLogInfo()    记录极简信息，适用于线上/线下环境，格式：@"Info timeStamp info"
 YDLogDetail()  记录详细信息，适用于线上/线下环境，格式：@"Deta timeStamp [thread] func str"
 YDLogDebug()   记录开发信息，适用于Debug环境，格式：@"Dbug timeStamp str"
 YDLogVerbose() 记录复杂信息，适用于Debug环境，格式：@"Verb timeStamp [thread] func in file:line desc"
 */

@interface YDLogService : NSObject
@property (nonatomic, copy, readonly)NSString *logFileDir;          // 日志文件夹路径
@property (nonatomic, copy, readonly)NSString *currentFilePath;     // 当前使用的日志文件路径

+ (instancetype)shared;

/**
 开启日志，是否开启hook模式，需要动态下发

 @param hook 是否开启hook模式
 */
- (void)startLogNeedHook:(BOOL)hook;


/**
 设置日志等级，默认为YDLogLevelDetail
 
 @param level 日志等级
 */
- (void)resetLogLevel:(YDLogLevel)level;


/**
 强制I/O做回写操作，只有需要即时展示当前日志内容的时候才做此操作
 */
- (void)syncFileData;


/**
 关闭当前文件，在applicationWillTerminate:中调用
 可以将文件大小更新到真实的文件大小
 */
- (void)closeFileBeforeShutDown;

- (void)clearAllLog;

- (NSArray *)getAllLogFileData;

- (NSDictionary *)getYDLogInfo:(NSString *)filePath;
@end

NS_ASSUME_NONNULL_END
