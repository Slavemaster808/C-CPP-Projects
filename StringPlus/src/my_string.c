#include "my_string.h"

void *my_memchr(const void *str, int c, my_size_t n) {
  my_size_t i = 0;
  const char *ptr = str;

  while (i < n) {
    if (*ptr == c) {
      ptr++;
      return (void *)(ptr - 1);
    }
    i++;
    ptr++;
  }
  return NULL;
}

int my_memcmp(const void *str1, const void *str2, my_size_t n) {
  my_size_t i = 0;
  int check = 0;
  const char *ptr1 = str1;
  const char *ptr2 = str2;

  while (i < n) {
    if (*ptr1 != *ptr2) {
      check = *ptr1 - *ptr2;
    }
    i++;
    ptr1++;
    ptr2++;
  }
  return check;
}

void *my_memcpy(void *dest, const void *src, my_size_t n) {
  const char *ptr_src = src;
  char *ptr_dest = dest;
  my_size_t i = 0;

  while (i < n) {
    *ptr_dest = *ptr_src;
    i++;
    ptr_dest++;
    ptr_src++;
  }
  return (void *)dest;
}

// void *my_memmove(void *dest, const void *src, my_size_t n) {
//   const char *ptr_src = src;
//   char *ptr_dest = dest;
//   my_size_t i = 0;

//   while (i < n) {
//     *ptr_dest = *ptr_src;
//     i++;
//     ptr_dest++;
//     ptr_src++;
//   }
//   return (void *)ptr_dest;
// }

void *my_memset(void *str, int c, my_size_t n) {
  my_size_t i = 0;
  char *ptr = str;

  while (i < n) {
    *ptr = c;
    ptr++;
    i++;
  }
  return (void *)str;
}

// char *my_strcat(char *dest, const char *src) {
//   char *ptr = dest;

//   for (; *dest != '\0'; dest++)
//     ;

//   while (*src != '\0') {
//     *dest = *src;
//     src++;
//     dest++;
//   }
//   return ptr;
// }

char *my_strncat(char *dest, const char *src, my_size_t n) {
  my_size_t i = 0;
  char *ptr = dest;

  for (; *dest != '\0'; dest++)
    ;

  while (i < n) {
    *dest = *src;
    src++;
    dest++;
    i++;
  }
  *dest = '\0';
  return ptr;
}

char *my_strchr(const char *str, int c) {
  for (; str != NULL && *str != (char)c; str++) {
    if (*str == '\0') {
      return NULL;
    }
  }
  return (char *)str;
}

// int my_strcmp(const char *str1, const char *str2) {
//   int check = 0;

//   while (1) {
//     if (*str1 != *str2) {
//       check = *str1 - *str2;
//     }
//     if (check != 0) {
//       break;
//     }
//     str1++;
//     str2++;
//   }
//   return check;
// }

int my_strncmp(const char *str1, const char *str2, my_size_t n) {
  int check = 0;
  my_size_t i = 0;

  while (i < n) {
    if (*str1 != *str2) {
      check = *str1 - *str2;
    }
    if (check != 0) {
      break;
    }
    i++;
    str1++;
    str2++;
  }
  return check;
}

char *my_strcpy(char *dest, const char *src) {
  char *ptr = dest;

  while ((*dest++ = *src++) != '\0')
    ;
  return ptr;
}

char *my_strncpy(char *dest, const char *src, my_size_t n) {
  char *ptr = dest;
  my_size_t i = 0;

  while (i < n) {
    *dest = *src;
    i++;
    dest++;
    src++;
  }
  return ptr;
}

my_size_t my_strcspn(const char *str1, const char *str2) {
  const char *ptr = str1;
  my_size_t cnt = 0;

  while (*ptr) {
    if (my_strchr(str2, *ptr)) {
      break;
    }
    cnt++;
    ptr++;
  }
  return cnt;
}

my_size_t my_strlen(const char *str) {
  my_size_t cnt = 0;

  while (*str) {
    cnt++;
    str++;
  }
  return cnt;
}

char *my_strpbrk(const char *str1, const char *str2) {
  const char *ptr = str1;
  const char *ret = NULL;

  for (; ptr != NULL && *ptr != '\0'; ptr++) {
    if (my_strchr(str2, *ptr)) {
      ret = ptr;
      break;
    }
  }
  return (char *)ret;
}

char *my_strrchr(const char *str, int c) {
  const char *ptr = NULL;

  do {
    if (*str == (char)c) {
      ptr = str;
    }
  } while (*str++);
  return (char *)ptr;
}

// my_size_t my_strspn(const char *str1, const char *str2) {
//   const char *ptr = str1;
//   my_size_t cnt = 0;

//   while (*ptr) {
//     if (!my_strchr(str2, *ptr)) {
//       break;
//     }
//     cnt++;
//     ptr++;
//   }
//   return cnt;
// }

char *my_strstr(const char *haystack, const char *needle) {
  const char *ptr = haystack;
  const char *ptp = needle;

  if (*ptp == '\0') {
    return (char *)ptr;
  }

  while (*ptr) {
    if (*ptp == *ptr) {
      const char *tmp_ptr = ptr;
      const char *tmp_ptp = ptp;
      while (*tmp_ptp && *tmp_ptr && *tmp_ptp == *tmp_ptr) {
        tmp_ptp++;
        tmp_ptr++;
      }
      if (!*tmp_ptp) {
        return (char *)ptr;
      }
    }
    ptr++;
  }
  return NULL;
}

char *my_strtok(char *str, const char *delim) {
  static char *last;
  int i = 0, flag = 0;
  char *s = NULL;
  if (str != NULL) {
    last = str;
  }
  if (last == NULL || *last == '\0') {
    return NULL;
  }
  s = last;
  while (*last) {
    int j = 0;
    while (delim[j] != '\0') {
      if (*last == delim[j]) {
        flag = 1;
        *last = '\0';
        last++;
        j = 0;
      } else
        j++;
    }
    if (flag == 0) {
      i++;
      last++;
    } else
      break;
  }
  if (i == 0) s = NULL;
  return s;
}

char *my_strerror(int errnum) {
  static char res[256];
  int len = 0;
#ifdef __linux__
#ifdef UBUNTU_PEER
  char Errors[][100] = {"Success",
                        "Operation not permitted",
                        "No such file or directory",
                        "No such process",
                        "Interrupted system call",
                        "Input/output error",
                        "No such device or address",
                        "Argument list too long",
                        "Exec format error",
                        "Bad file descriptor",
                        "No child processes",
                        "Resource temporarily unavailable",
                        "Cannot allocate memory",
                        "Permission denied",
                        "Bad address",
                        "Block device required",
                        "Device or resource busy",
                        "File exists",
                        "Invalid cross-device link",
                        "No such device",
                        "Not a directory",
                        "Is a directory",
                        "Invalid argument",
                        "Too many open files in system",
                        "Too many open files",
                        "Inappropriate ioctl for device",
                        "Text file busy",
                        "File too large",
                        "No space left on device",
                        "Illegal seek",
                        "Read-only file system",
                        "Too many links",
                        "Broken pipe",
                        "Numerical argument out of domain",
                        "Numerical result out of range",
                        "Resource deadlock avoided",
                        "File name too long",
                        "No locks available",
                        "Function not implemented",
                        "Directory not empty",
                        "Too many levels of symbolic links",
                        "Unknown error 41",
                        "No message of desired type",
                        "Identifier removed",
                        "Channel number out of range",
                        "Level 2 not synchronized",
                        "Level 3 halted",
                        "Level 3 reset",
                        "Link number out of range",
                        "Protocol driver not attached",
                        "No CSI structure available",
                        "Level 2 halted",
                        "Invalid exchange",
                        "Invalid request descriptor",
                        "Exchange full",
                        "No anode",
                        "Invalid request code",
                        "Invalid slot",
                        "Unknown error 58",
                        "Bad font file format",
                        "Device not a stream",
                        "No data available",
                        "Timer expired",
                        "Out of streams resources",
                        "Machine is not on the network",
                        "Package not installed",
                        "Object is remote",
                        "Link has been severed",
                        "Advertise error",
                        "Srmount error",
                        "Communication error on send",
                        "Protocol error",
                        "Multihop attempted",
                        "RFS specific error",
                        "Bad message",
                        "Value too large for defined data type",
                        "Name not unique on network",
                        "File descriptor in bad state",
                        "Remote address changed",
                        "Can not access a needed shared library",
                        "Accessing a corrupted shared library",
                        ".lib section in a.out corrupted",
                        "Attempting to link in too many shared libraries",
                        "Cannot exec a shared library directly",
                        "Invalid or incomplete multibyte or wide character",
                        "Interrupted system call should be restarted",
                        "Streams pipe error",
                        "Too many users",
                        "Socket operation on non-socket",
                        "Destination address required",
                        "Message too long",
                        "Protocol wrong type for socket",
                        "Protocol not available",
                        "Protocol not supported",
                        "Socket type not supported",
                        "Operation not supported",
                        "Protocol family not supported",
                        "Address family not supported by protocol",
                        "Address already in use",
                        "Cannot assign requested address",
                        "Network is down",
                        "Network is unreachable",
                        "Network dropped connection on reset",
                        "Software caused connection abort",
                        "Connection reset by peer",
                        "No buffer space available",
                        "Transport endpoint is already connected",
                        "Transport endpoint is not connected",
                        "Cannot send after transport endpoint shutdown",
                        "Too many references: cannot splice",
                        "Connection timed out",
                        "Connection refused",
                        "Host is down",
                        "No route to host",
                        "Operation already in progress",
                        "Operation now in progress",
                        "Stale file handle",
                        "Structure needs cleaning",
                        "Not a XENIX named type file",
                        "No XENIX semaphores available",
                        "Is a named type file",
                        "Remote I/O error",
                        "Disk quota exceeded",
                        "No medium found",
                        "Wrong medium type",
                        "Operation canceled",
                        "Required key not available",
                        "Key has expired",
                        "Key has been revoked",
                        "Key was rejected by service",
                        "Owner died",
                        "State not recoverable",
                        "Operation not possible due to RF-kill",
                        "Memory page has hardware error"};
  len = sizeof(Errors) / sizeof(Errors[0]);
  if (errnum < 0 || errnum >= len) {
    my_sprintf(res, "Unknown error %d", errnum);
  } else
    my_strcpy(res, Errors[errnum]);
#else
  char Errors[][100] = {"No error information",
                        "Operation not permitted",
                        "No such file or directory",
                        "No such process",
                        "Interrupted system call",
                        "I/O error",
                        "No such device or address",
                        "Argument list too long",
                        "Exec format error",
                        "Bad file descriptor",
                        "No child process",
                        "Resource temporarily unavailable",
                        "Out of memory",
                        "Permission denied",
                        "Bad address",
                        "Block device required",
                        "Resource busy",
                        "File exists",
                        "Cross-device link",
                        "No such device",
                        "Not a directory",
                        "Is a directory",
                        "Invalid argument",
                        "Too many open files in system",
                        "No file descriptors available",
                        "Not a tty",
                        "Text file busy",
                        "File too large",
                        "No space left on device",
                        "Invalid seek",
                        "Read-only file system",
                        "Too many links",
                        "Broken pipe",
                        "Domain error",
                        "Result not representable",
                        "Resource deadlock would occur",
                        "Filename too long",
                        "No locks available",
                        "Function not implemented",
                        "Directory not empty",
                        "Symbolic link loop",
                        "No error information",
                        "No message of desired type",
                        "Identifier removed",
                        "No error information",
                        "No error information",
                        "No error information",
                        "No error information",
                        "No error information",
                        "No error information",
                        "No error information",
                        "No error information",
                        "No error information",
                        "No error information",
                        "No error information",
                        "No error information",
                        "No error information",
                        "No error information",
                        "No error information",
                        "No error information",
                        "Device not a stream",
                        "No data available",
                        "Device timeout",
                        "Out of streams resources",
                        "No error information",
                        "No error information",
                        "No error information",
                        "Link has been severed",
                        "No error information",
                        "No error information",
                        "No error information",
                        "Protocol error",
                        "Multihop attempted",
                        "No error information",
                        "Bad message",
                        "Value too large for data type",
                        "No error information",
                        "File descriptor in bad state",
                        "No error information",
                        "No error information",
                        "No error information",
                        "No error information",
                        "No error information",
                        "No error information",
                        "Illegal byte sequence",
                        "No error information",
                        "No error information",
                        "No error information",
                        "Not a socket",
                        "Destination address required",
                        "Message too large",
                        "Protocol wrong type for socket",
                        "Protocol not available",
                        "Protocol not supported",
                        "Socket type not supported",
                        "Not supported",
                        "Protocol family not supported",
                        "Address family not supported by protocol",
                        "Address in use",
                        "Address not available",
                        "Network is down",
                        "Network unreachable",
                        "Connection reset by network",
                        "Connection aborted",
                        "Connection reset by peer",
                        "No buffer space available",
                        "Socket is connected",
                        "Socket not connected",
                        "Cannot send after socket shutdown",
                        "No error information",
                        "Operation timed out",
                        "Connection refused",
                        "Host is down",
                        "Host is unreachable",
                        "Operation already in progress",
                        "Operation in progress",
                        "Stale file handle",
                        "No error information",
                        "No error information",
                        "No error information",
                        "No error information",
                        "Remote I/O error",
                        "Quota exceeded",
                        "No medium found",
                        "Wrong medium type",
                        "Operation canceled",
                        "Required key not available",
                        "Key has expired",
                        "Key has been revoked",
                        "Key was rejected by service",
                        "Previous owner died",
                        "State not recoverable",
                        "No error information"};
  len = sizeof(Errors) / sizeof(Errors[0]);
  if (errnum < 0 || errnum >= len) {
    errnum = 0;
  }
  my_strcpy(res, Errors[errnum]);
#endif  // UBUNTU - else
#endif  // __linux__
#ifdef __APPLE__
  char Errors[][100] = {"Undefined error: 0",
                        "Operation not permitted",
                        "No such file or directory",
                        "No such process",
                        "Interrupted system call",
                        "Input/output error",
                        "Device not configured",
                        "Argument list too long",
                        "Exec format error",
                        "Bad file descriptor",
                        "No child processes",
                        "Resource deadlock avoided",
                        "Cannot allocate memory",
                        "Permission denied",
                        "Bad address",
                        "Block device required",
                        "Resource busy",
                        "File exists",
                        "Cross-device link",
                        "Operation not supported by device",
                        "Not a directory",
                        "Is a directory",
                        "Invalid argument",
                        "Too many open files in system",
                        "Too many open files",
                        "Inappropriate ioctl for device",
                        "Text file busy",
                        "File too large",
                        "No space left on device",
                        "Illegal seek",
                        "Read-only file system",
                        "Too many links",
                        "Broken pipe",
                        "Numerical argument out of domain",
                        "Result too large",
                        "Resource temporarily unavailable",
                        "Operation now in progress",
                        "Operation already in progress",
                        "Socket operation on non-socket",
                        "Destination address required",
                        "Message too long",
                        "Protocol wrong type for socket",
                        "Protocol not available",
                        "Protocol not supported",
                        "Socket type not supported",
                        "Operation not supported",
                        "Protocol family not supported",
                        "Address family not supported by protocol family",
                        "Address already in use",
                        "Can't assign requested address",
                        "Network is down",
                        "Network is unreachable",
                        "Network dropped connection on reset",
                        "Software caused connection abort",
                        "Connection reset by peer",
                        "No buffer space available",
                        "Socket is already connected",
                        "Socket is not connected",
                        "Can't send after socket shutdown",
                        "Too many references: can't splice",
                        "Operation timed out",
                        "Connection refused",
                        "Too many levels of symbolic links",
                        "File name too long",
                        "Host is down",
                        "No route to host",
                        "Directory not empty",
                        "Too many processes",
                        "Too many users",
                        "Disc quota exceeded",
                        "Stale NFS file handle",
                        "Too many levels of remote in path",
                        "RPC struct is bad",
                        "RPC version wrong",
                        "RPC prog. not avail",
                        "Program version wrong",
                        "Bad procedure for program",
                        "No locks available",
                        "Function not implemented",
                        "Inappropriate file type or format",
                        "Authentication error",
                        "Need authenticator",
                        "Device power is off",
                        "Device error",
                        "Value too large to be stored in data type",
                        "Bad executable (or shared library)",
                        "Bad CPU type in executable",
                        "Shared library version mismatch",
                        "Malformed Mach-o file",
                        "Operation canceled",
                        "Identifier removed",
                        "No message of desired type",
                        "Illegal byte sequence",
                        "Attribute not found",
                        "Bad message",
                        "EMULTIHOP (Reserved)",
                        "No message available on STREAM",
                        "ENOLINK (Reserved)",
                        "No STREAM resources",
                        "Not a STREAM",
                        "Protocol error",
                        "STREAM ioctl timeout",
                        "Operation not supported on socket",
                        "Policy not found",
                        "State not recoverable",
                        "Previous owner died",
                        "Interface output queue is full"};
  len = sizeof(Errors) / sizeof(Errors[0]);
  if (errnum < 0 || errnum >= len) {
    my_sprintf(res, "Unknown error: %d", errnum);
  } else
    my_strcpy(res, Errors[errnum]);
#endif
  return res;
}

int my_sprintf(char *str, const char *format, ...) {
  va_list arg;
  FILE *fp;
  int cnt_args = 0;

  fp = fopen("temp.txt", "w+");
  va_start(arg, format);
  cnt_args = vfprintf(fp, format, arg);
  va_end(arg);
  fclose(fp);
  fp = fopen("temp.txt", "rb");
  while (fp && !feof(fp)) {
    int c = fgetc(fp);
    if (c >= 0 && c <= 255) {
      *str = c;
      str++;
    }
  }
  *str = 0;
  if (fp != NULL) {
    fclose(fp);
  }
  remove("temp.txt");
  return cnt_args;
}

int my_sscanf(const char *str, const char *format, ...) {
  va_list arg;
  FILE *fp;
  int cnt_args = 0;

  fp = fopen("temp.txt", "w+");
  fprintf(fp, "%s", str);
  fclose(fp);
  fp = fopen("temp.txt", "rb");
  va_start(arg, format);
  cnt_args = vfscanf(fp, format, arg);
  va_end(arg);
  if (fp != NULL) {
    fclose(fp);
  }
  remove("temp.txt");
  return cnt_args;
}

// char *intToString(char *str, int num) {
//   int nmbr, len = 0;
//   int check = 0;

//   if (num < 0) {
//     check = 1;
//     num = -num;
//   }

//   int tmp = num;

//   while (tmp != 0) {
//     tmp = tmp / 10;
//     len++;
//   }

//   char buff[len];
//   for (int i = 0; i < len; i++) {
//     nmbr = num % 10;
//     num = num / 10;
//     buff[len - (i + 1)] = nmbr + '0';
//   }

//   if (check == 1) {
//     *str = '-';
//     str++;
//   }

//   for (int i = 0; i < len; i++) {
//     *str = buff[i];
//     str++;
//   }
//   return str;
// }

void *my_to_upper(const char *str) {
  char *temp = malloc(sizeof(char) * (my_strlen(str) + 1));
  my_strcpy(temp, str);
  char *ptr = temp;

  while (*ptr) {
    if (*ptr >= 'a' && *ptr <= 'z') {
      *ptr = *ptr - 32;
    }
    ptr++;
  }
  return (void *)temp;
}

void *my_to_lower(const char *str) {
  char *temp = malloc(sizeof(char) * (my_strlen(str) + 1));
  my_strcpy(temp, str);
  char *ptr = temp;

  while (*ptr) {
    if (*ptr >= 'A' && *ptr <= 'Z') {
      *ptr = *ptr + 32;
    }
    ptr++;
  }
  return (void *)temp;
}

void *my_insert(const char *src, const char *str, my_size_t start_index) {
  if (src == NULL || str == NULL || *src == '\0' || *str == '\0') {
    return NULL;
  }
  char *temp_src = calloc(sizeof(char), my_strlen(src) + 1);
  char *ptr_temp_src = temp_src;
  char *temp_str = calloc(sizeof(char), my_strlen(str) + 1);
  char *ptr_temp_str = temp_str;
  char *ptr = NULL;
  char *ret = NULL;
  my_strcpy(temp_src, src);
  my_strcpy(temp_str, str);

  if (start_index > my_strlen(src)) {
    free(temp_src);
    free(temp_str);
    return NULL;
  } else {
    ptr = calloc(sizeof(char), (my_strlen(src) + my_strlen(str)) + 1);
    ret = ptr;
    my_size_t i = 0;

    while (*temp_src && i < start_index) {
      *ptr = *temp_src;
      temp_src++;
      ptr++;
      i++;
    }

    while (*temp_str) {
      *ptr = *temp_str;
      ptr++;
      temp_str++;
    }

    while (*temp_src) {
      *ptr = *temp_src;
      ptr++;
      temp_src++;
    }
  }

  free(ptr_temp_str);
  free(ptr_temp_src);
  return (void *)ret;
}

void *my_trim(const char *src, const char *trim_chars) {
  if (src == NULL) {
    return NULL;
  }
  my_size_t src_len = my_strlen(src);
  my_size_t start_pos = 0;
  my_size_t end_pos = src_len - 1;

  while (start_pos < src_len && my_strchr(trim_chars, src[start_pos])) {
    start_pos++;
  }
  while (end_pos > start_pos && my_strchr(trim_chars, src[end_pos])) {
    end_pos--;
  }

  my_size_t res_len = end_pos - start_pos + 1;
  char *res = (char *)malloc(sizeof(char) * (res_len + 1));
  if (trim_chars == NULL) {
    my_strcpy(res, src);
    return (void *)res;
  } else {
    my_memcpy(res, src + start_pos, res_len);
    res[res_len] = '\0';
  }
  return res;
}