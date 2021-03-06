/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCKSOCKET_H
#define _MOCKSOCKET_H

#ifndef __USE_GNU
#define __USE_GNU
#endif

#include "sys/socket.h"

/* Ignore the following warnings, since we are copying code */
#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if !defined(__clang__)
#pragma GCC diagnostic ignored "-Wpragmas"
#endif
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC diagnostic ignored "-Wduplicate-decl-specifier"
#endif

void Mocksocket_Init(void);
void Mocksocket_Destroy(void);
void Mocksocket_Verify(void);

struct mmsghdr *msg;

#define connect_IgnoreAndReturn(cmock_retval) connect_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void connect_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return);
#define connect_ExpectAnyArgsAndReturn(cmock_retval) connect_CMockExpectAnyArgsAndReturn(__LINE__, cmock_retval)
void connect_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return);
#define connect_ExpectAndReturn(__fd, __addr, __len, cmock_retval) connect_CMockExpectAndReturn(__LINE__, __fd, __addr, __len, cmock_retval)
void connect_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int __fd, __CONST_SOCKADDR_ARG __addr, socklen_t __len, int cmock_to_return);
typedef int (*CMOCK_connect_CALLBACK)(int __fd, __CONST_SOCKADDR_ARG __addr, socklen_t __len, int cmock_num_calls);
void connect_StubWithCallback(CMOCK_connect_CALLBACK Callback);
#define connect_IgnoreArg___fd() connect_CMockIgnoreArg___fd(__LINE__)
void connect_CMockIgnoreArg___fd(UNITY_LINE_TYPE cmock_line);
#define connect_IgnoreArg___addr() connect_CMockIgnoreArg___addr(__LINE__)
void connect_CMockIgnoreArg___addr(UNITY_LINE_TYPE cmock_line);
#define connect_IgnoreArg___len() connect_CMockIgnoreArg___len(__LINE__)
void connect_CMockIgnoreArg___len(UNITY_LINE_TYPE cmock_line);
#define send_IgnoreAndReturn(cmock_retval) send_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void send_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, ssize_t cmock_to_return);
#define send_ExpectAnyArgsAndReturn(cmock_retval) send_CMockExpectAnyArgsAndReturn(__LINE__, cmock_retval)
void send_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, ssize_t cmock_to_return);
#define send_ExpectAndReturn(__fd, __buf, __n, __flags, cmock_retval) send_CMockExpectAndReturn(__LINE__, __fd, __buf, __n, __flags, cmock_retval)
void send_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int __fd, const void *__buf, size_t __n, int __flags, ssize_t cmock_to_return);
typedef ssize_t(*CMOCK_send_CALLBACK)(int __fd, const void *__buf, size_t __n, int __flags, int cmock_num_calls);
void send_StubWithCallback(CMOCK_send_CALLBACK Callback);
#define send_IgnoreArg___fd() send_CMockIgnoreArg___fd(__LINE__)
void send_CMockIgnoreArg___fd(UNITY_LINE_TYPE cmock_line);
#define send_IgnoreArg___buf() send_CMockIgnoreArg___buf(__LINE__)
void send_CMockIgnoreArg___buf(UNITY_LINE_TYPE cmock_line);
#define send_IgnoreArg___n() send_CMockIgnoreArg___n(__LINE__)
void send_CMockIgnoreArg___n(UNITY_LINE_TYPE cmock_line);
#define send_IgnoreArg___flags() send_CMockIgnoreArg___flags(__LINE__)
void send_CMockIgnoreArg___flags(UNITY_LINE_TYPE cmock_line);
#define recv_IgnoreAndReturn(cmock_retval) recv_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void recv_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, ssize_t cmock_to_return);
#define recv_ExpectAnyArgsAndReturn(cmock_retval) recv_CMockExpectAnyArgsAndReturn(__LINE__, cmock_retval)
void recv_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, ssize_t cmock_to_return);
#define recv_ExpectAndReturn(__fd, __buf, __n, __flags, cmock_retval) recv_CMockExpectAndReturn(__LINE__, __fd, __buf, __n, __flags, cmock_retval)
void recv_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int __fd, void *__buf, size_t __n, int __flags, ssize_t cmock_to_return);
typedef ssize_t(*CMOCK_recv_CALLBACK)(int __fd, void *__buf, size_t __n, int __flags, int cmock_num_calls);
void recv_StubWithCallback(CMOCK_recv_CALLBACK Callback);
#define recv_IgnoreArg___fd() recv_CMockIgnoreArg___fd(__LINE__)
void recv_CMockIgnoreArg___fd(UNITY_LINE_TYPE cmock_line);
#define recv_IgnoreArg___buf() recv_CMockIgnoreArg___buf(__LINE__)
void recv_CMockIgnoreArg___buf(UNITY_LINE_TYPE cmock_line);
#define recv_IgnoreArg___n() recv_CMockIgnoreArg___n(__LINE__)
void recv_CMockIgnoreArg___n(UNITY_LINE_TYPE cmock_line);
#define recv_IgnoreArg___flags() recv_CMockIgnoreArg___flags(__LINE__)
void recv_CMockIgnoreArg___flags(UNITY_LINE_TYPE cmock_line);
#define sendto_IgnoreAndReturn(cmock_retval) sendto_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void sendto_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, ssize_t cmock_to_return);
#define sendto_ExpectAnyArgsAndReturn(cmock_retval) sendto_CMockExpectAnyArgsAndReturn(__LINE__, cmock_retval)
void sendto_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, ssize_t cmock_to_return);
#define sendto_ExpectAndReturn(__fd, __buf, __n, __flags, __addr, __addr_len, cmock_retval) sendto_CMockExpectAndReturn(__LINE__, __fd, __buf, __n, __flags, __addr, __addr_len, cmock_retval)
void sendto_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int __fd, const void *__buf, size_t __n, int __flags, __CONST_SOCKADDR_ARG __addr, socklen_t __addr_len, ssize_t cmock_to_return);
typedef ssize_t(*CMOCK_sendto_CALLBACK)(int __fd, const void *__buf, size_t __n, int __flags, __CONST_SOCKADDR_ARG __addr, socklen_t __addr_len, int cmock_num_calls);
void sendto_StubWithCallback(CMOCK_sendto_CALLBACK Callback);
#define sendto_IgnoreArg___fd() sendto_CMockIgnoreArg___fd(__LINE__)
void sendto_CMockIgnoreArg___fd(UNITY_LINE_TYPE cmock_line);
#define sendto_IgnoreArg___buf() sendto_CMockIgnoreArg___buf(__LINE__)
void sendto_CMockIgnoreArg___buf(UNITY_LINE_TYPE cmock_line);
#define sendto_IgnoreArg___n() sendto_CMockIgnoreArg___n(__LINE__)
void sendto_CMockIgnoreArg___n(UNITY_LINE_TYPE cmock_line);
#define sendto_IgnoreArg___flags() sendto_CMockIgnoreArg___flags(__LINE__)
void sendto_CMockIgnoreArg___flags(UNITY_LINE_TYPE cmock_line);
#define sendto_IgnoreArg___addr() sendto_CMockIgnoreArg___addr(__LINE__)
void sendto_CMockIgnoreArg___addr(UNITY_LINE_TYPE cmock_line);
#define sendto_IgnoreArg___addr_len() sendto_CMockIgnoreArg___addr_len(__LINE__)
void sendto_CMockIgnoreArg___addr_len(UNITY_LINE_TYPE cmock_line);
#define recvfrom_IgnoreAndReturn(cmock_retval) recvfrom_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void recvfrom_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, ssize_t cmock_to_return);
#define recvfrom_ExpectAnyArgsAndReturn(cmock_retval) recvfrom_CMockExpectAnyArgsAndReturn(__LINE__, cmock_retval)
void recvfrom_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, ssize_t cmock_to_return);
#define recvfrom_ExpectAndReturn(__fd, __buf, __n, __flags, __addr, __addr_len, cmock_retval) recvfrom_CMockExpectAndReturn(__LINE__, __fd, __buf, __n, __flags, __addr, __addr_len, cmock_retval)
void recvfrom_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int __fd, void *__restrict __buf, size_t __n, int __flags, __SOCKADDR_ARG __addr, socklen_t *__restrict __addr_len, ssize_t cmock_to_return);
typedef ssize_t(*CMOCK_recvfrom_CALLBACK)(int __fd, void *__restrict __buf, size_t __n, int __flags, __SOCKADDR_ARG __addr, socklen_t *__restrict __addr_len, int cmock_num_calls);
void recvfrom_StubWithCallback(CMOCK_recvfrom_CALLBACK Callback);
#define recvfrom_IgnoreArg___fd() recvfrom_CMockIgnoreArg___fd(__LINE__)
void recvfrom_CMockIgnoreArg___fd(UNITY_LINE_TYPE cmock_line);
#define recvfrom_IgnoreArg___buf() recvfrom_CMockIgnoreArg___buf(__LINE__)
void recvfrom_CMockIgnoreArg___buf(UNITY_LINE_TYPE cmock_line);
#define recvfrom_IgnoreArg___n() recvfrom_CMockIgnoreArg___n(__LINE__)
void recvfrom_CMockIgnoreArg___n(UNITY_LINE_TYPE cmock_line);
#define recvfrom_IgnoreArg___flags() recvfrom_CMockIgnoreArg___flags(__LINE__)
void recvfrom_CMockIgnoreArg___flags(UNITY_LINE_TYPE cmock_line);
#define recvfrom_IgnoreArg___addr() recvfrom_CMockIgnoreArg___addr(__LINE__)
void recvfrom_CMockIgnoreArg___addr(UNITY_LINE_TYPE cmock_line);
#define recvfrom_IgnoreArg___addr_len() recvfrom_CMockIgnoreArg___addr_len(__LINE__)
void recvfrom_CMockIgnoreArg___addr_len(UNITY_LINE_TYPE cmock_line);
#define sendmsg_IgnoreAndReturn(cmock_retval) sendmsg_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void sendmsg_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, ssize_t cmock_to_return);
#define sendmsg_ExpectAnyArgsAndReturn(cmock_retval) sendmsg_CMockExpectAnyArgsAndReturn(__LINE__, cmock_retval)
void sendmsg_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, ssize_t cmock_to_return);
#define sendmsg_ExpectAndReturn(__fd, __message, __flags, cmock_retval) sendmsg_CMockExpectAndReturn(__LINE__, __fd, __message, __flags, cmock_retval)
void sendmsg_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int __fd, const struct msghdr *__message, int __flags, ssize_t cmock_to_return);
typedef ssize_t(*CMOCK_sendmsg_CALLBACK)(int __fd, const struct msghdr *__message, int __flags, int cmock_num_calls);
void sendmsg_StubWithCallback(CMOCK_sendmsg_CALLBACK Callback);
#define sendmsg_IgnoreArg___fd() sendmsg_CMockIgnoreArg___fd(__LINE__)
void sendmsg_CMockIgnoreArg___fd(UNITY_LINE_TYPE cmock_line);
#define sendmsg_IgnoreArg___message() sendmsg_CMockIgnoreArg___message(__LINE__)
void sendmsg_CMockIgnoreArg___message(UNITY_LINE_TYPE cmock_line);
#define sendmsg_IgnoreArg___flags() sendmsg_CMockIgnoreArg___flags(__LINE__)
void sendmsg_CMockIgnoreArg___flags(UNITY_LINE_TYPE cmock_line);
#define sendmmsg_IgnoreAndReturn(cmock_retval) sendmmsg_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void sendmmsg_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return);
#define sendmmsg_ExpectAnyArgsAndReturn(cmock_retval) sendmmsg_CMockExpectAnyArgsAndReturn(__LINE__, cmock_retval)
void sendmmsg_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return);
#define sendmmsg_ExpectAndReturn(__fd, __vmessages, __vlen, __flags, cmock_retval) sendmmsg_CMockExpectAndReturn(__LINE__, __fd, __vmessages, __vlen, __flags, cmock_retval)
void sendmmsg_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int __fd, struct mmsghdr *__vmessages, unsigned int __vlen, int __flags, int cmock_to_return);
typedef int (*CMOCK_sendmmsg_CALLBACK)(int __fd, struct mmsghdr *__vmessages, unsigned int __vlen, int __flags, int cmock_num_calls);
void sendmmsg_StubWithCallback(CMOCK_sendmmsg_CALLBACK Callback);
#define sendmmsg_IgnoreArg___fd() sendmmsg_CMockIgnoreArg___fd(__LINE__)
void sendmmsg_CMockIgnoreArg___fd(UNITY_LINE_TYPE cmock_line);
#define sendmmsg_IgnoreArg___vmessages() sendmmsg_CMockIgnoreArg___vmessages(__LINE__)
void sendmmsg_CMockIgnoreArg___vmessages(UNITY_LINE_TYPE cmock_line);
#define sendmmsg_IgnoreArg___vlen() sendmmsg_CMockIgnoreArg___vlen(__LINE__)
void sendmmsg_CMockIgnoreArg___vlen(UNITY_LINE_TYPE cmock_line);
#define sendmmsg_IgnoreArg___flags() sendmmsg_CMockIgnoreArg___flags(__LINE__)
void sendmmsg_CMockIgnoreArg___flags(UNITY_LINE_TYPE cmock_line);
#define recvmsg_IgnoreAndReturn(cmock_retval) recvmsg_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void recvmsg_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, ssize_t cmock_to_return);
#define recvmsg_ExpectAnyArgsAndReturn(cmock_retval) recvmsg_CMockExpectAnyArgsAndReturn(__LINE__, cmock_retval)
void recvmsg_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, ssize_t cmock_to_return);
#define recvmsg_ExpectAndReturn(__fd, __message, __flags, cmock_retval) recvmsg_CMockExpectAndReturn(__LINE__, __fd, __message, __flags, cmock_retval)
void recvmsg_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int __fd, struct msghdr *__message, int __flags, ssize_t cmock_to_return);
typedef ssize_t(*CMOCK_recvmsg_CALLBACK)(int __fd, struct msghdr *__message, int __flags, int cmock_num_calls);
void recvmsg_StubWithCallback(CMOCK_recvmsg_CALLBACK Callback);
#define recvmsg_IgnoreArg___fd() recvmsg_CMockIgnoreArg___fd(__LINE__)
void recvmsg_CMockIgnoreArg___fd(UNITY_LINE_TYPE cmock_line);
#define recvmsg_IgnoreArg___message() recvmsg_CMockIgnoreArg___message(__LINE__)
void recvmsg_CMockIgnoreArg___message(UNITY_LINE_TYPE cmock_line);
#define recvmsg_IgnoreArg___flags() recvmsg_CMockIgnoreArg___flags(__LINE__)
void recvmsg_CMockIgnoreArg___flags(UNITY_LINE_TYPE cmock_line);
#define recvmmsg_IgnoreAndReturn(cmock_retval) recvmmsg_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void recvmmsg_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return);
#define recvmmsg_ExpectAnyArgsAndReturn(cmock_retval) recvmmsg_CMockExpectAnyArgsAndReturn(__LINE__, cmock_retval)
void recvmmsg_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return);
#define recvmmsg_ExpectAndReturn(__fd, __vmessages, __vlen, __flags, __tmo, cmock_retval) recvmmsg_CMockExpectAndReturn(__LINE__, __fd, __vmessages, __vlen, __flags, __tmo, cmock_retval)
void recvmmsg_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int __fd, struct mmsghdr *__vmessages, unsigned int __vlen, int __flags, struct timespec *__tmo, int cmock_to_return);
typedef int (*CMOCK_recvmmsg_CALLBACK)(int __fd, struct mmsghdr *__vmessages, unsigned int __vlen, int __flags, struct timespec *__tmo, int cmock_num_calls);
void recvmmsg_StubWithCallback(CMOCK_recvmmsg_CALLBACK Callback);
#define recvmmsg_IgnoreArg___fd() recvmmsg_CMockIgnoreArg___fd(__LINE__)
void recvmmsg_CMockIgnoreArg___fd(UNITY_LINE_TYPE cmock_line);
#define recvmmsg_IgnoreArg___vmessages() recvmmsg_CMockIgnoreArg___vmessages(__LINE__)
void recvmmsg_CMockIgnoreArg___vmessages(UNITY_LINE_TYPE cmock_line);
#define recvmmsg_IgnoreArg___vlen() recvmmsg_CMockIgnoreArg___vlen(__LINE__)
void recvmmsg_CMockIgnoreArg___vlen(UNITY_LINE_TYPE cmock_line);
#define recvmmsg_IgnoreArg___flags() recvmmsg_CMockIgnoreArg___flags(__LINE__)
void recvmmsg_CMockIgnoreArg___flags(UNITY_LINE_TYPE cmock_line);
#define recvmmsg_IgnoreArg___tmo() recvmmsg_CMockIgnoreArg___tmo(__LINE__)
void recvmmsg_CMockIgnoreArg___tmo(UNITY_LINE_TYPE cmock_line);
#define accept_IgnoreAndReturn(cmock_retval) accept_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void accept_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return);
#define accept_ExpectAnyArgsAndReturn(cmock_retval) accept_CMockExpectAnyArgsAndReturn(__LINE__, cmock_retval)
void accept_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return);
#define accept_ExpectAndReturn(__fd, __addr, __addr_len, cmock_retval) accept_CMockExpectAndReturn(__LINE__, __fd, __addr, __addr_len, cmock_retval)
void accept_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int __fd, __SOCKADDR_ARG __addr, socklen_t *__restrict __addr_len, int cmock_to_return);
typedef int (*CMOCK_accept_CALLBACK)(int __fd, __SOCKADDR_ARG __addr, socklen_t *__restrict __addr_len, int cmock_num_calls);
void accept_StubWithCallback(CMOCK_accept_CALLBACK Callback);
#define accept_IgnoreArg___fd() accept_CMockIgnoreArg___fd(__LINE__)
void accept_CMockIgnoreArg___fd(UNITY_LINE_TYPE cmock_line);
#define accept_IgnoreArg___addr() accept_CMockIgnoreArg___addr(__LINE__)
void accept_CMockIgnoreArg___addr(UNITY_LINE_TYPE cmock_line);
#define accept_IgnoreArg___addr_len() accept_CMockIgnoreArg___addr_len(__LINE__)
void accept_CMockIgnoreArg___addr_len(UNITY_LINE_TYPE cmock_line);
#define accept4_IgnoreAndReturn(cmock_retval) accept4_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void accept4_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return);
#define accept4_ExpectAnyArgsAndReturn(cmock_retval) accept4_CMockExpectAnyArgsAndReturn(__LINE__, cmock_retval)
void accept4_CMockExpectAnyArgsAndReturn(UNITY_LINE_TYPE cmock_line, int cmock_to_return);
#define accept4_ExpectAndReturn(__fd, __addr, __addr_len, __flags, cmock_retval) accept4_CMockExpectAndReturn(__LINE__, __fd, __addr, __addr_len, __flags, cmock_retval)
void accept4_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, int __fd, __SOCKADDR_ARG __addr, socklen_t *__restrict __addr_len, int __flags, int cmock_to_return);
typedef int (*CMOCK_accept4_CALLBACK)(int __fd, __SOCKADDR_ARG __addr, socklen_t *__restrict __addr_len, int __flags, int cmock_num_calls);
void accept4_StubWithCallback(CMOCK_accept4_CALLBACK Callback);
#define accept4_IgnoreArg___fd() accept4_CMockIgnoreArg___fd(__LINE__)
void accept4_CMockIgnoreArg___fd(UNITY_LINE_TYPE cmock_line);
#define accept4_IgnoreArg___addr() accept4_CMockIgnoreArg___addr(__LINE__)
void accept4_CMockIgnoreArg___addr(UNITY_LINE_TYPE cmock_line);
#define accept4_IgnoreArg___addr_len() accept4_CMockIgnoreArg___addr_len(__LINE__)
void accept4_CMockIgnoreArg___addr_len(UNITY_LINE_TYPE cmock_line);
#define accept4_IgnoreArg___flags() accept4_CMockIgnoreArg___flags(__LINE__)
void accept4_CMockIgnoreArg___flags(UNITY_LINE_TYPE cmock_line);

#endif
