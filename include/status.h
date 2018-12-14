/*
 * *****************************************************************************
 *
 * Copyright 2018 Gavin D. Howard
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 *
 * *****************************************************************************
 *
 * All bc status codes.
 *
 */

#ifndef BC_STATUS_H
#define BC_STATUS_H

typedef enum BcStatus {

	BC_STATUS_SUCCESS = 0,

	BC_STATUS_ALLOC_ERR,
	BC_STATUS_IO_ERR,
	BC_STATUS_BIN_FILE,
	BC_STATUS_PATH_IS_DIR,

	BC_STATUS_PARSE_BAD_CHAR,
	BC_STATUS_PARSE_NO_STRING_END,
	BC_STATUS_PARSE_NO_COMMENT_END,
	BC_STATUS_PARSE_BAD_TOKEN,
	BC_STATUS_PARSE_BAD_EXP,
	BC_STATUS_PARSE_EMPTY_EXP,
	BC_STATUS_PARSE_BAD_PRINT,
	BC_STATUS_PARSE_BAD_FUNC,
	BC_STATUS_PARSE_BAD_ASSIGN,
	BC_STATUS_PARSE_NO_AUTO,
	BC_STATUS_PARSE_DUPLICATE_LOCAL,
	BC_STATUS_PARSE_NO_BLOCK_END,
	BC_STATUS_PARSE_EOF,
#if DC_ENABLED
	BC_STATUS_PARSE_EXTENDED_REG,
#endif // DC_ENABLED

	BC_STATUS_MATH_NEGATIVE,
	BC_STATUS_MATH_NON_INTEGER,
	BC_STATUS_MATH_OVERFLOW,
	BC_STATUS_MATH_DIVIDE_BY_ZERO,
	BC_STATUS_MATH_BAD_STRING,

	BC_STATUS_EXEC_FILE_ERR,
	BC_STATUS_EXEC_MISMATCHED_PARAMS,
	BC_STATUS_EXEC_UNDEFINED_FUNC,
	BC_STATUS_EXEC_FILE_NOT_EXECUTABLE,
	BC_STATUS_EXEC_NUM_LEN,
	BC_STATUS_EXEC_NAME_LEN,
	BC_STATUS_EXEC_STRING_LEN,
	BC_STATUS_EXEC_ARRAY_LEN,
	BC_STATUS_EXEC_BAD_IBASE,
	BC_STATUS_EXEC_BAD_SCALE,
	BC_STATUS_EXEC_BAD_READ_EXPR,
	BC_STATUS_EXEC_REC_READ,
	BC_STATUS_EXEC_BAD_TYPE,
	BC_STATUS_EXEC_BAD_OBASE,
	BC_STATUS_EXEC_SIGNAL,
	BC_STATUS_EXEC_STACK,

#if BC_ENABLED
	BC_STATUS_POSIX_NAME_LEN,
	BC_STATUS_POSIX_COMMENT,
	BC_STATUS_POSIX_BAD_KW,
	BC_STATUS_POSIX_DOT,
	BC_STATUS_POSIX_RET,
	BC_STATUS_POSIX_BOOL,
	BC_STATUS_POSIX_REL_POS,
	BC_STATUS_POSIX_MULTIREL,
	BC_STATUS_POSIX_FOR1,
	BC_STATUS_POSIX_FOR2,
	BC_STATUS_POSIX_FOR3,
	BC_STATUS_POSIX_BRACE,
#endif // BC_ENABLED

	BC_STATUS_INVALID_OPTION,

	BC_STATUS_QUIT,

} BcStatus;

#define BC_ERR_IDX_VM (0)
#define BC_ERR_IDX_PARSE (1)
#define BC_ERR_IDX_MATH (2)
#define BC_ERR_IDX_EXEC (3)
#if BC_ENABLED
#define BC_ERR_IDX_POSIX (4)
#endif // BC_ENABLED

#endif // BC_STATUS_H
