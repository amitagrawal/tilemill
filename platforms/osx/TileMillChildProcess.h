//
//  TileMillChildProcess.h
//  TileMill
//
//  Created by Will White on 8/2/11.
//  Copyright 2011 Development Seed. All rights reserved.
//

@class TileMillChildProcess;

@protocol TileMillChildProcessDelegate

@optional

- (void)childProcessDidStart:(TileMillChildProcess *)process;
- (void)childProcessDidSendFirstData:(TileMillChildProcess *)process;
- (void)childProcess:(TileMillChildProcess *)process didSendOutput:(NSString *)output;
- (void)childProcessDidFinish:(TileMillChildProcess *)process;

@end

#pragma mark -

@interface TileMillChildProcess : NSObject
{
    __unsafe_unretained id <TileMillChildProcessDelegate>delegate;
    NSTask *task;
    NSString *basePath;
    NSString *command;
    BOOL launched;
    NSInteger port;
}

@property (nonatomic, unsafe_unretained) id <TileMillChildProcessDelegate>delegate;
@property (nonatomic, readonly, assign, getter=isLaunched) BOOL launched;
@property (nonatomic, assign) NSInteger port;

- (id)initWithBasePath:(NSString *)inBasePath command:(NSString *)inCommand;
- (void)startProcess;
- (void)stopProcess;

@end