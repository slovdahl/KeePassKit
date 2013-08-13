//
//  KPKTree+Serializing.h
//  KeePassKit
//
//  Created by Michael Starke on 16.07.13.
//  Copyright (c) 2013 HicknHack Software GmbH. All rights reserved.
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#import "KPKTree.h"

@interface KPKTree (Serializing)

/**
 *	Initalizes the Tree with the data contained int he given url
 *	@param	url	URL to load the tree data from
 *	@param	password	Password to decrpyt the tree with
 *  @param  error Error if initalization doesnt work
 *	@return	Newly created tree
 */
- (id)initWithContentsOfUrl:(NSURL *)url password:(KPKPassword *)password error:(NSError **)error;
/**
 *	Initalizes a tree with the given data. The data is the raw encrypted file data
 *	@param	data	Data to load the tree from. Supply raw undecrypted file data
 *	@param	password	Password to decrypt the tree
 *  @param  error Error if initalization doesnt work
 *	@return	Tree with contents of data
 */
- (id)initWithData:(NSData *)data password:(KPKPassword *)password error:(NSError **)error;
/**
 *	Creates the tree with the contents of the xml file
 *	@param	url	URL to the xml file to load
 *  @param  error the error object returned on failure
 *	@return	Tree created from the xml data
 */
- (id)initWithXmlContentsOfURL:(NSURL *)url error:(NSError **)error;
/**
 *	Encrypts the tree with the given password and the version. This operation is possibly lossy
 *	@param	password	The password used to encrypt the tree
 *	@param	version	the version to write. Possibly lossy
 *	@param	error	error that might occur
 *	@return	data with the encrypted tree
 */
- (NSData *)encryptWithPassword:(KPKPassword *)password forVersion:(KPKVersion)version error:(NSError **)error;
/**
 *	Serializes the tree into the KeePass xml file
 *	@return	XML file string. Pretty printed
 */
- (NSString *)XmlString;

@end