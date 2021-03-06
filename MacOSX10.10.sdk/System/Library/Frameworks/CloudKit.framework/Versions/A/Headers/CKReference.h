//
//  CKReference.h
//  CloudKit
//
//  Copyright (c) 2014 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CKRecord, CKRecordID, CKAsset;

typedef NS_ENUM(NSUInteger, CKReferenceAction) {
    /* When the referred record is deleted, this record is unchanged, and has a dangling pointer */
    CKReferenceActionNone       = 0,
    /* When the referred record is deleted then this record is also deleted. */
    CKReferenceActionDeleteSelf = 1,
} NS_ENUM_AVAILABLE(10_10, 8_0);


NS_CLASS_AVAILABLE(10_10, 8_0)
@interface CKReference : NSObject <NSSecureCoding, NSCopying>

- (instancetype)init NS_UNAVAILABLE;

/* It is acceptable to relate two records that have not yet been uploaded to the server, but those records must be uploaded to the server in the same operation.
 If a record references a record that does not exist on the server and is not in the current save operation it will result in an error. */
- (instancetype)initWithRecordID:(CKRecordID *)recordID action:(CKReferenceAction)action NS_DESIGNATED_INITIALIZER;
- (instancetype)initWithRecord:(CKRecord *)record action:(CKReferenceAction)action;

@property (nonatomic, readonly, assign) CKReferenceAction referenceAction;

@property (nonatomic, readonly, copy) CKRecordID *recordID;

@end
