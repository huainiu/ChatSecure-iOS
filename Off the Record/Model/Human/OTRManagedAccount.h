//
//  OTRManagedAccount.h
//  Off the Record
//
//  Created by Christopher Ballinger on 1/10/13.
//  Copyright (c) 2013 Chris Ballinger. All rights reserved.
//
//  This file is part of ChatSecure.
//
//  ChatSecure is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  ChatSecure is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with ChatSecure.  If not, see <http://www.gnu.org/licenses/>.

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "_OTRManagedAccount.h"
#import "OTRManagedBuddy.h"
#import "OTRConstants.h"


extern NSString *const OTRAccountProtocolKey;
extern NSString *const OTRAccountRememberPasswordKey;

extern NSString *const OTRAimImageName;
extern NSString *const OTRGoogleTalkImageName;
extern NSString *const OTRFacebookImageName;
extern NSString *const OTRXMPPImageName;
extern NSString *const OTRXMPPTorImageName;



@interface OTRManagedAccount : _OTRManagedAccount

@property (nonatomic, retain) NSString *password; // nil if rememberPassword = NO, not stored in memory
@property (nonatomic,readonly) BOOL isConnected;

- (Class) protocolClass;
- (NSString *) providerName;
- (OTRAccountType)accountType;
- (UIImage *)accountImage;

- (void)setDefaultsWithProtocol:(NSString*)newProtocol;

- (void)setAllBuddiesStatuts:(OTRBuddyStatus)status inContext:(NSManagedObjectContext *)context;
- (void)deleteAllAccountMessagesInContext:(NSManagedObjectContext *)context;

- (void)prepareBuddiesandMessagesForDeletion;

- (NSDictionary *)dictionaryRepresentation;
+ (instancetype)createWithDictionary:(NSDictionary *)dictionary forContext:(NSManagedObjectContext *)context;


//Goes through all accounts checks if it's connected againgst ProtocolManager and adjusts buddy status
+(void)resetAccountsConnectionStatus;

+(OTRManagedAccount *)accountForAccountType:(OTRAccountType)accountType inContext:(NSManagedObjectContext *)context;

@end