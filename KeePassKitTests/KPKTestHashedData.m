//
//  KPKHashedDataTest.m
//  MacPass
//
//  Created by Michael Starke on 08.08.13.
//  Copyright (c) 2013 HicknHack Software GmbH. All rights reserved.
//

@import XCTest;

#import "KeePassKit.h"

@interface KPKTestHashedData : XCTestCase

@end

@implementation KPKTestHashedData

- (void)testSHA256Hashing {
  NSData *data = [NSData dataWithRandomBytes:1024*1024*8 + 512]; // 8 MB Data, to use more than one block
  NSData *hashedData = data.hashedSha256Data;
  NSData *unhashedData = hashedData.unhashedSha256Data;
  XCTAssertTrue([unhashedData isEqualToData:data], @"Data needs to be the same after hashing and unhashing");
}

- (void)testHmacSha256Hasing {
  /* use more than 1 block of unaligned data */
  NSData *data = [NSData dataWithRandomBytes:1024*1024*8 + 512];
  NSData *key = [NSData dataWithRandomBytes:64];
  NSError *error;
  NSData *hashedData = [data hashedHmacSha256DataWithKey:key error:&error];
  NSData *unhashedData = [hashedData unhashedHmacSha256DataWithKey:key error:&error];
  XCTAssertEqualObjects(data, unhashedData, @"Hashed and unhashed data are the same");
}
@end
