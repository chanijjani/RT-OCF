/****************************************************************************
 *
 * Copyright 2017 Samsung Electronics All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific
 * language governing permissions and limitations under the License.
 *
 ****************************************************************************/

#include <fcntl.h>
#include "unity.h"
#include "unity_fixture.h"
#include "ocf_types.h"
#include "rt_logger.h"
#include "rt_rep.h"
#include "rt_uuid.h"
#include "rt_sec_cred_resource.h"
#include "rt_sec_persistent_storage.h"
#include "rt_list.h"
#include "test_common.h"

#define TAG "TEST_CRED_RES"

#ifdef CONFIG_ENABLE_RT_OCF
static char CRED_FILE[] = "/mnt/svr_cred.dat";
static char CRED_NO_FILE[] = "/mnt/svr_no_cred.dat";
#else
static char CRED_FILE[] = "svr_cred.dat";
static char CRED_NO_FILE[] = "svr_no_cred.dat";
#endif

static uint8_t cred_data[] = {
	0xBF, 0x65, 0x63, 0x72, 0x65, 0x64, 0x73, 0x84, 0xA6, 0x66, 0x63, 0x72, 0x65, 0x64, 0x69, 0x64,
	0x01, 0x6B, 0x73, 0x75, 0x62, 0x6A, 0x65, 0x63, 0x74, 0x75, 0x75, 0x69, 0x64, 0x78, 0x24, 0x34,
	0x64, 0x36, 0x31, 0x37, 0x35, 0x36, 0x36, 0x2D, 0x36, 0x31, 0x36, 0x33, 0x2D, 0x37, 0x34, 0x37,
	0x35, 0x2D, 0x37, 0x32, 0x36, 0x35, 0x2D, 0x37, 0x32, 0x34, 0x33, 0x36, 0x35, 0x37, 0x32, 0x37,
	0x34, 0x33, 0x30, 0x68, 0x63, 0x72, 0x65, 0x64, 0x74, 0x79, 0x70, 0x65, 0x08, 0x69, 0x63, 0x72,
	0x65, 0x64, 0x75, 0x73, 0x61, 0x67, 0x65, 0x74, 0x6F, 0x69, 0x63, 0x2E, 0x73, 0x65, 0x63, 0x2E,
	0x63, 0x72, 0x65, 0x64, 0x2E, 0x6D, 0x66, 0x67, 0x63, 0x65, 0x72, 0x74, 0x6A, 0x70, 0x75, 0x62,
	0x6C, 0x69, 0x63, 0x64, 0x61, 0x74, 0x61, 0xA2, 0x68, 0x65, 0x6E, 0x63, 0x6F, 0x64, 0x69, 0x6E,
	0x67, 0x74, 0x6F, 0x69, 0x63, 0x2E, 0x73, 0x65, 0x63, 0x2E, 0x65, 0x6E, 0x63, 0x6F, 0x64, 0x69,
	0x6E, 0x67, 0x2E, 0x64, 0x65, 0x72, 0x64, 0x64, 0x61, 0x74, 0x61, 0x59, 0x01, 0xFD, 0x30, 0x82,
	0x01, 0xF9, 0x30, 0x82, 0x01, 0x9F, 0xA0, 0x03, 0x02, 0x01, 0x02, 0x02, 0x01, 0x07, 0x30, 0x0A,
	0x06, 0x08, 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x04, 0x03, 0x02, 0x30, 0x68, 0x31, 0x32, 0x30, 0x30,
	0x06, 0x03, 0x55, 0x04, 0x03, 0x0C, 0x29, 0x75, 0x75, 0x69, 0x64, 0x3A, 0x33, 0x31, 0x33, 0x31,
	0x33, 0x31, 0x33, 0x31, 0x2D, 0x33, 0x31, 0x33, 0x31, 0x2D, 0x33, 0x31, 0x33, 0x31, 0x2D, 0x33,
	0x31, 0x33, 0x31, 0x2D, 0x33, 0x31, 0x33, 0x31, 0x33, 0x31, 0x33, 0x31, 0x33, 0x31, 0x33, 0x31,
	0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x4B, 0x52, 0x31, 0x10, 0x30,
	0x0E, 0x06, 0x03, 0x55, 0x04, 0x0A, 0x0C, 0x07, 0x53, 0x61, 0x6D, 0x73, 0x75, 0x6E, 0x67, 0x31,
	0x13, 0x30, 0x11, 0x06, 0x03, 0x55, 0x04, 0x0B, 0x0C, 0x0A, 0x4F, 0x43, 0x46, 0x20, 0x53, 0x75,
	0x62, 0x20, 0x43, 0x41, 0x30, 0x1E, 0x17, 0x0D, 0x31, 0x36, 0x31, 0x31, 0x30, 0x34, 0x31, 0x35,
	0x30, 0x38, 0x30, 0x39, 0x5A, 0x17, 0x0D, 0x33, 0x36, 0x31, 0x31, 0x30, 0x34, 0x31, 0x35, 0x30,
	0x38, 0x30, 0x39, 0x5A, 0x30, 0x68, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13,
	0x02, 0x4B, 0x52, 0x31, 0x10, 0x30, 0x0E, 0x06, 0x03, 0x55, 0x04, 0x0A, 0x13, 0x07, 0x53, 0x61,
	0x6D, 0x73, 0x75, 0x6E, 0x67, 0x31, 0x13, 0x30, 0x11, 0x06, 0x03, 0x55, 0x04, 0x0B, 0x13, 0x0A,
	0x4F, 0x43, 0x46, 0x20, 0x44, 0x65, 0x76, 0x69, 0x63, 0x65, 0x31, 0x32, 0x30, 0x30, 0x06, 0x03,
	0x55, 0x04, 0x03, 0x13, 0x29, 0x75, 0x75, 0x69, 0x64, 0x3A, 0x36, 0x61, 0x37, 0x35, 0x37, 0x33,
	0x37, 0x34, 0x2D, 0x37, 0x37, 0x36, 0x66, 0x2D, 0x37, 0x32, 0x36, 0x62, 0x2D, 0x34, 0x34, 0x36,
	0x35, 0x2D, 0x37, 0x36, 0x35, 0x35, 0x37, 0x35, 0x36, 0x39, 0x36, 0x34, 0x33, 0x30, 0x30, 0x59,
	0x30, 0x13, 0x06, 0x07, 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x02, 0x01, 0x06, 0x08, 0x2A, 0x86, 0x48,
	0xCE, 0x3D, 0x03, 0x01, 0x07, 0x03, 0x42, 0x00, 0x04, 0xA8, 0x64, 0x46, 0xF9, 0xA4, 0xB5, 0xA4,
	0x24, 0x92, 0x2F, 0x4F, 0xB1, 0x67, 0x30, 0xC8, 0x0B, 0x21, 0xBE, 0xF5, 0x58, 0xF7, 0x92, 0x51,
	0x7D, 0x77, 0x37, 0xFD, 0xC4, 0x9F, 0xD8, 0xCF, 0x98, 0x29, 0x10, 0xF6, 0x17, 0x80, 0x56, 0x98,
	0xDD, 0x4E, 0xE4, 0xDD, 0xA6, 0xC3, 0xB3, 0x09, 0x18, 0x24, 0x6B, 0x4D, 0x35, 0x40, 0xC7, 0x4B,
	0x83, 0x6B, 0x1E, 0xCA, 0xC1, 0xA1, 0x22, 0xB1, 0xBA, 0xA3, 0x3A, 0x30, 0x38, 0x30, 0x36, 0x06,
	0x03, 0x55, 0x1D, 0x11, 0x04, 0x2F, 0x30, 0x2D, 0x82, 0x2B, 0x75, 0x73, 0x65, 0x72, 0x69, 0x64,
	0x3A, 0x36, 0x37, 0x34, 0x34, 0x36, 0x37, 0x31, 0x64, 0x2D, 0x32, 0x39, 0x36, 0x33, 0x2D, 0x34,
	0x63, 0x39, 0x32, 0x2D, 0x61, 0x38, 0x62, 0x62, 0x2D, 0x33, 0x38, 0x31, 0x31, 0x37, 0x62, 0x34,
	0x38, 0x36, 0x35, 0x38, 0x65, 0x30, 0x0A, 0x06, 0x08, 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x04, 0x03,
	0x02, 0x03, 0x48, 0x00, 0x30, 0x45, 0x02, 0x21, 0x00, 0xD7, 0x5F, 0x26, 0xC5, 0xD4, 0x86, 0x78,
	0x2C, 0x9C, 0x8C, 0xDA, 0xAF, 0x3C, 0xB6, 0x05, 0x62, 0x29, 0x8E, 0x87, 0x3E, 0xDD, 0x1C, 0x29,
	0x7C, 0x64, 0xA4, 0x11, 0x29, 0x89, 0xCF, 0x8C, 0x65, 0x02, 0x20, 0x60, 0x62, 0x5A, 0x59, 0x1E,
	0xEA, 0x2E, 0x1B, 0x58, 0xE1, 0xA5, 0x2B, 0x1A, 0xD9, 0xF0, 0x86, 0xC5, 0xF1, 0xF2, 0x65, 0xBE,
	0x8F, 0xB8, 0xC0, 0x24, 0xCB, 0x6C, 0x9F, 0xC6, 0x9C, 0x9F, 0xCC, 0x6B, 0x70, 0x72, 0x69, 0x76,
	0x61, 0x74, 0x65, 0x64, 0x61, 0x74, 0x61, 0xA2, 0x68, 0x65, 0x6E, 0x63, 0x6F, 0x64, 0x69, 0x6E,
	0x67, 0x74, 0x6F, 0x69, 0x63, 0x2E, 0x73, 0x65, 0x63, 0x2E, 0x65, 0x6E, 0x63, 0x6F, 0x64, 0x69,
	0x6E, 0x67, 0x2E, 0x72, 0x61, 0x77, 0x64, 0x64, 0x61, 0x74, 0x61, 0x58, 0x7A, 0x30, 0x78, 0x02,
	0x01, 0x01, 0x04, 0x21, 0x00, 0xE0, 0x0D, 0x6E, 0x16, 0x2B, 0x33, 0xF5, 0x6D, 0x50, 0xB4, 0x0E,
	0x57, 0x28, 0x8D, 0xF2, 0x84, 0xF7, 0x6D, 0x5C, 0xE7, 0xF1, 0xF8, 0x00, 0xF7, 0x55, 0x98, 0x82,
	0xAB, 0x12, 0x6B, 0x58, 0x13, 0xA0, 0x0A, 0x06, 0x08, 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x03, 0x01,
	0x07, 0xA1, 0x44, 0x03, 0x42, 0x00, 0x04, 0xA8, 0x64, 0x46, 0xF9, 0xA4, 0xB5, 0xA4, 0x24, 0x92,
	0x2F, 0x4F, 0xB1, 0x67, 0x30, 0xC8, 0x0B, 0x21, 0xBE, 0xF5, 0x58, 0xF7, 0x92, 0x51, 0x7D, 0x77,
	0x37, 0xFD, 0xC4, 0x9F, 0xD8, 0xCF, 0x98, 0x29, 0x10, 0xF6, 0x17, 0x80, 0x56, 0x98, 0xDD, 0x4E,
	0xE4, 0xDD, 0xA6, 0xC3, 0xB3, 0x09, 0x18, 0x24, 0x6B, 0x4D, 0x35, 0x40, 0xC7, 0x4B, 0x83, 0x6B,
	0x1E, 0xCA, 0xC1, 0xA1, 0x22, 0xB1, 0xBA, 0xA5, 0x66, 0x63, 0x72, 0x65, 0x64, 0x69, 0x64, 0x02,
	0x6B, 0x73, 0x75, 0x62, 0x6A, 0x65, 0x63, 0x74, 0x75, 0x75, 0x69, 0x64, 0x61, 0x2A, 0x68, 0x63,
	0x72, 0x65, 0x64, 0x74, 0x79, 0x70, 0x65, 0x08, 0x69, 0x63, 0x72, 0x65, 0x64, 0x75, 0x73, 0x61,
	0x67, 0x65, 0x77, 0x6F, 0x69, 0x63, 0x2E, 0x73, 0x65, 0x63, 0x2E, 0x63, 0x72, 0x65, 0x64, 0x2E,
	0x6D, 0x66, 0x67, 0x74, 0x72, 0x75, 0x73, 0x74, 0x63, 0x61, 0x6C, 0x6F, 0x70, 0x74, 0x69, 0x6F,
	0x6E, 0x61, 0x6C, 0x64, 0x61, 0x74, 0x61, 0xA3, 0x68, 0x65, 0x6E, 0x63, 0x6F, 0x64, 0x69, 0x6E,
	0x67, 0x74, 0x6F, 0x69, 0x63, 0x2E, 0x73, 0x65, 0x63, 0x2E, 0x65, 0x6E, 0x63, 0x6F, 0x64, 0x69,
	0x6E, 0x67, 0x2E, 0x64, 0x65, 0x72, 0x64, 0x64, 0x61, 0x74, 0x61, 0x59, 0x01, 0xD3, 0x30, 0x82,
	0x01, 0xCF, 0x30, 0x82, 0x01, 0x75, 0xA0, 0x03, 0x02, 0x01, 0x02, 0x02, 0x01, 0x01, 0x30, 0x0A,
	0x06, 0x08, 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x04, 0x03, 0x02, 0x30, 0x68, 0x31, 0x32, 0x30, 0x30,
	0x06, 0x03, 0x55, 0x04, 0x03, 0x0C, 0x29, 0x75, 0x75, 0x69, 0x64, 0x3A, 0x33, 0x31, 0x33, 0x31,
	0x33, 0x31, 0x33, 0x31, 0x2D, 0x33, 0x31, 0x33, 0x31, 0x2D, 0x33, 0x31, 0x33, 0x31, 0x2D, 0x33,
	0x31, 0x33, 0x31, 0x2D, 0x33, 0x31, 0x33, 0x31, 0x33, 0x31, 0x33, 0x31, 0x33, 0x31, 0x33, 0x31,
	0x31, 0x0B, 0x30, 0x09, 0x06, 0x03, 0x55, 0x04, 0x06, 0x13, 0x02, 0x4B, 0x52, 0x31, 0x10, 0x30,
	0x0E, 0x06, 0x03, 0x55, 0x04, 0x0A, 0x0C, 0x07, 0x53, 0x61, 0x6D, 0x73, 0x75, 0x6E, 0x67, 0x31,
	0x13, 0x30, 0x11, 0x06, 0x03, 0x55, 0x04, 0x0B, 0x0C, 0x0A, 0x4F, 0x43, 0x46, 0x20, 0x53, 0x75,
	0x62, 0x20, 0x43, 0x41, 0x30, 0x1E, 0x17, 0x0D, 0x31, 0x36, 0x31, 0x31, 0x30, 0x34, 0x31, 0x32,
	0x34, 0x39, 0x33, 0x32, 0x5A, 0x17, 0x0D, 0x33, 0x36, 0x31, 0x31, 0x30, 0x34, 0x31, 0x32, 0x34,
	0x39, 0x33, 0x32, 0x5A, 0x30, 0x68, 0x31, 0x32, 0x30, 0x30, 0x06, 0x03, 0x55, 0x04, 0x03, 0x0C,
	0x29, 0x75, 0x75, 0x69, 0x64, 0x3A, 0x33, 0x31, 0x33, 0x31, 0x33, 0x31, 0x33, 0x31, 0x2D, 0x33,
	0x31, 0x33, 0x31, 0x2D, 0x33, 0x31, 0x33, 0x31, 0x2D, 0x33, 0x31, 0x33, 0x31, 0x2D, 0x33, 0x31,
	0x33, 0x31, 0x33, 0x31, 0x33, 0x31, 0x33, 0x31, 0x33, 0x31, 0x31, 0x0B, 0x30, 0x09, 0x06, 0x03,
	0x55, 0x04, 0x06, 0x13, 0x02, 0x4B, 0x52, 0x31, 0x10, 0x30, 0x0E, 0x06, 0x03, 0x55, 0x04, 0x0A,
	0x0C, 0x07, 0x53, 0x61, 0x6D, 0x73, 0x75, 0x6E, 0x67, 0x31, 0x13, 0x30, 0x11, 0x06, 0x03, 0x55,
	0x04, 0x0B, 0x0C, 0x0A, 0x4F, 0x43, 0x46, 0x20, 0x53, 0x75, 0x62, 0x20, 0x43, 0x41, 0x30, 0x59,
	0x30, 0x13, 0x06, 0x07, 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x02, 0x01, 0x06, 0x08, 0x2A, 0x86, 0x48,
	0xCE, 0x3D, 0x03, 0x01, 0x07, 0x03, 0x42, 0x00, 0x04, 0xA3, 0x34, 0xEF, 0x1F, 0x49, 0x79, 0x64,
	0xDF, 0x84, 0x0D, 0xF2, 0xF5, 0xBA, 0x2B, 0xFD, 0x6A, 0x02, 0x41, 0xFA, 0xD9, 0xC0, 0xD8, 0xE8,
	0x8A, 0x71, 0x82, 0x1A, 0x46, 0xFD, 0x5C, 0xF8, 0x00, 0xF5, 0x09, 0x96, 0x27, 0xBD, 0x54, 0x73,
	0xAE, 0x49, 0x56, 0x78, 0xEB, 0x2D, 0x6F, 0x62, 0x47, 0x4C, 0xFA, 0xC6, 0xC1, 0xC8, 0xB9, 0xDB,
	0x47, 0xFA, 0x86, 0x37, 0x3A, 0xB8, 0x33, 0x0E, 0xBC, 0xA3, 0x10, 0x30, 0x0E, 0x30, 0x0C, 0x06,
	0x03, 0x55, 0x1D, 0x13, 0x04, 0x05, 0x30, 0x03, 0x01, 0x01, 0xFF, 0x30, 0x0A, 0x06, 0x08, 0x2A,
	0x86, 0x48, 0xCE, 0x3D, 0x04, 0x03, 0x02, 0x03, 0x48, 0x00, 0x30, 0x45, 0x02, 0x21, 0x00, 0xAF,
	0x5E, 0x06, 0xA4, 0x40, 0x02, 0x57, 0x9F, 0x13, 0xF4, 0x7B, 0x19, 0xF2, 0x99, 0x07, 0x8A, 0x7B,
	0x35, 0xFB, 0x6B, 0x2C, 0x70, 0x7F, 0x7C, 0xC9, 0x26, 0x31, 0x9F, 0x74, 0x4F, 0x2B, 0xB4, 0x02,
	0x20, 0x53, 0x3A, 0xC7, 0x4F, 0xA7, 0x7F, 0x42, 0xAA, 0xFE, 0xAA, 0x2E, 0xED, 0x7E, 0x1B, 0xA2,
	0xA4, 0x40, 0xDE, 0xA6, 0xA9, 0x9C, 0x7C, 0x33, 0x77, 0xD8, 0x6A, 0xC4, 0x23, 0x1B, 0x1D, 0x6D,
	0x3B, 0x67, 0x72, 0x65, 0x76, 0x73, 0x74, 0x61, 0x74, 0xF4, 0xA5, 0x66, 0x63, 0x72, 0x65, 0x64,
	0x69, 0x64, 0x03, 0x6B, 0x73, 0x75, 0x62, 0x6A, 0x65, 0x63, 0x74, 0x75, 0x75, 0x69, 0x64, 0x78,
	0x24, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x2D, 0x31, 0x31, 0x31, 0x31, 0x2D, 0x31,
	0x31, 0x31, 0x31, 0x2D, 0x31, 0x31, 0x31, 0x31, 0x2D, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31,
	0x31, 0x31, 0x31, 0x31, 0x31, 0x68, 0x63, 0x72, 0x65, 0x64, 0x74, 0x79, 0x70, 0x65, 0x01, 0x66,
	0x70, 0x65, 0x72, 0x69, 0x6F, 0x64, 0x78, 0x1F, 0x32, 0x30, 0x31, 0x35, 0x30, 0x36, 0x33, 0x30,
	0x54, 0x30, 0x36, 0x30, 0x30, 0x30, 0x30, 0x2F, 0x32, 0x30, 0x39, 0x39, 0x30, 0x39, 0x32, 0x30,
	0x54, 0x32, 0x32, 0x30, 0x30, 0x30, 0x30, 0x6B, 0x70, 0x72, 0x69, 0x76, 0x61, 0x74, 0x65, 0x64,
	0x61, 0x74, 0x61, 0xA2, 0x68, 0x65, 0x6E, 0x63, 0x6F, 0x64, 0x69, 0x6E, 0x67, 0x74, 0x6F, 0x69,
	0x63, 0x2E, 0x73, 0x65, 0x63, 0x2E, 0x65, 0x6E, 0x63, 0x6F, 0x64, 0x69, 0x6E, 0x67, 0x2E, 0x72,
	0x61, 0x77, 0x64, 0x64, 0x61, 0x74, 0x61, 0x50, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41,
	0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0xA5, 0x66, 0x63, 0x72, 0x65, 0x64, 0x69, 0x64,
	0x04, 0x6B, 0x73, 0x75, 0x62, 0x6A, 0x65, 0x63, 0x74, 0x75, 0x75, 0x69, 0x64, 0x78, 0x24, 0x32,
	0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x2D, 0x32, 0x32, 0x32, 0x32, 0x2D, 0x32, 0x32, 0x32,
	0x32, 0x2D, 0x32, 0x32, 0x32, 0x32, 0x2D, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32, 0x32,
	0x32, 0x32, 0x32, 0x68, 0x63, 0x72, 0x65, 0x64, 0x74, 0x79, 0x70, 0x65, 0x01, 0x66, 0x70, 0x65,
	0x72, 0x69, 0x6F, 0x64, 0x78, 0x1F, 0x32, 0x30, 0x31, 0x35, 0x30, 0x36, 0x33, 0x30, 0x54, 0x30,
	0x36, 0x30, 0x30, 0x30, 0x30, 0x2F, 0x32, 0x30, 0x39, 0x39, 0x30, 0x39, 0x32, 0x30, 0x54, 0x32,
	0x32, 0x30, 0x30, 0x30, 0x30, 0x6B, 0x70, 0x72, 0x69, 0x76, 0x61, 0x74, 0x65, 0x64, 0x61, 0x74,
	0x61, 0xA2, 0x68, 0x65, 0x6E, 0x63, 0x6F, 0x64, 0x69, 0x6E, 0x67, 0x74, 0x6F, 0x69, 0x63, 0x2E,
	0x73, 0x65, 0x63, 0x2E, 0x65, 0x6E, 0x63, 0x6F, 0x64, 0x69, 0x6E, 0x67, 0x2E, 0x72, 0x61, 0x77,
	0x64, 0x64, 0x61, 0x74, 0x61, 0x50, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42,
	0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x6A, 0x72, 0x6F, 0x77, 0x6E, 0x65, 0x72, 0x75, 0x75, 0x69,
	0x64, 0x78, 0x24, 0x34, 0x64, 0x36, 0x31, 0x37, 0x35, 0x36, 0x36, 0x2D, 0x36, 0x31, 0x36, 0x33,
	0x2D, 0x37, 0x34, 0x37, 0x35, 0x2D, 0x37, 0x32, 0x36, 0x35, 0x2D, 0x37, 0x32, 0x34, 0x33, 0x36,
	0x35, 0x37, 0x32, 0x37, 0x34, 0x33, 0x30, 0xFF
};

static const int test_credid = 4;
static const char *test_subjectuuid = "22222222-2222-2222-2222-222222222222";
static const char *test_period = "20150630T060000/20990920T220000";

static FILE *cred_fopen(const char *path, const char *mode)
{
	(void)path;
	return fopen(CRED_FILE, mode);
}

static FILE *cred_no_fopen(const char *path, const char *mode)
{
	(void)path;
	return fopen(CRED_NO_FILE, mode);
}

static rt_persistent_storage_handler_s ps_doxm = { cred_fopen, fread, fwrite, fclose };
static rt_persistent_storage_handler_s ps_pstat = { cred_fopen, fread, fwrite, fclose };
static rt_persistent_storage_handler_s ps_cred = { cred_fopen, fread, fwrite, fclose };
static rt_persistent_storage_handler_s ps_acl2 = { cred_fopen, fread, fwrite, fclose };

TEST_GROUP(test_sec_cred_resource);

TEST_SETUP(test_sec_cred_resource)
{
	int fd;
	if (0 < (fd = open(CRED_FILE, O_WRONLY | O_CREAT, 0644))) {
		write(fd, cred_data, sizeof(cred_data));
		close(fd);
	}

	rt_sec_register_ps_handler(&ps_doxm, &ps_pstat, &ps_cred, &ps_acl2);
	rt_mem_pool_init();
	rt_random_init();
	rt_resource_manager_init("Samsung", "1.0");
}

TEST_TEAR_DOWN(test_sec_cred_resource)
{
	rt_resource_manager_terminate();
	rt_mem_pool_terminate();
}

TEST(test_sec_cred_resource, rt_sec_cred_init)
{
	// Given

	// When
	ocf_result_t ret = rt_sec_cred_init();

	// Then
	TEST_ASSERT_EQUAL_INT(OCF_OK, ret);

	rt_sec_cred_terminate();
}

TEST(test_sec_cred_resource, rt_sec_cred_get_by_subjectuuid)
{
	// Given
	ocf_result_t ret = rt_sec_cred_init();

	// When
	rt_uuid_t uuid;
	rt_uuid_str2uuid(test_subjectuuid, uuid);
	rt_sec_creds_s *cred = NULL;
	ret = rt_sec_cred_get_by_subjectuuid(uuid, &cred);

	// Then
	TEST_ASSERT_EQUAL_INT(OCF_OK, ret);
	TEST_ASSERT_EQUAL_STRING(test_period, cred->period);
	TEST_ASSERT_EQUAL_INT(test_credid, cred->cred_id);

	rt_sec_cred_terminate();
}

TEST(test_sec_cred_resource, rt_convert_cred_to_payload)
{
	// Given
	rt_sec_cred_init();

	// When
	rt_rep_encoder_s *rep = rt_convert_cred_to_payload(NULL, false);

	RT_LOG_BUFFER_D(TAG, rep->payload, rep->payload_size);

	// Then
	TEST_ASSERT_EQUAL_INT(sizeof(cred_data), rep->payload_size);

	rt_sec_cred_terminate();
	rt_rep_encoder_release(rep);
}

TEST_GROUP_RUNNER(test_sec_cred_resource)
{
	RUN_TEST_CASE(test_sec_cred_resource, rt_sec_cred_init);
	RUN_TEST_CASE(test_sec_cred_resource, rt_sec_cred_get_by_subjectuuid);
	RUN_TEST_CASE(test_sec_cred_resource, rt_convert_cred_to_payload);
}

#ifndef CONFIG_ENABLE_RT_OCF

static void RunAllTests(void)
{
	RUN_TEST_GROUP(test_sec_cred_resource);
}

int main(int argc, const char *argv[])
{
	return UnityMain(argc, argv, RunAllTests);
}

#endif
