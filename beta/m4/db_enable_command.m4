AC_DEFUN([DB_ENABLE_COMMAND],
[
  AC_MSG_CHECKING([whether to enable $1 command])
  AC_ARG_ENABLE([$1],
    AS_HELP_STRING([--enable-$1],[enable $1 command @<:@$2@:>@]),
    [db_cv_enable_command_$1=$enableval],
    AC_CACHE_VAL([db_cv_enable_command_$1], [db_cv_enable_command_$1=$2]))
  if test "[${db_cv_enable_command_$1}]" = yes; then
    AC_DEFINE_UNQUOTED([ENABLE_$3],[1],[whether to enable $1 command])
  fi
  AC_MSG_RESULT([$db_cv_enable_command_$1])
])


AC_DEFUN([DB_ENABLE_COMMANDS],
[
  AC_MSG_CHECKING([whether to enable $1 commands])
  AC_ARG_ENABLE([$1],
    AS_HELP_STRING([--enable-$1],[enable $1 commands @<:@$2@:>@]),
    [db_cv_enable_command_$1=$enableval],
    AC_CACHE_VAL([db_cv_enable_command_$1], [db_cv_enable_command_$1=$2]))
  if test "[${db_cv_enable_command_$1}]" = yes; then
    AC_DEFINE_UNQUOTED([ENABLE_$3],[1],[whether to enable $1 commands])
  fi
  AC_MSG_RESULT([$db_cv_enable_command_$1])
])

AC_DEFUN([DB_ENABLE_GENERIC],
[
  AC_MSG_CHECKING([whether to enable $4])
  AC_ARG_ENABLE([$1],
    AS_HELP_STRING([--enable-$1],[enable $4 @<:@$2@:>@]),
    [db_cv_enable_command_$1=$enableval],
    AC_CACHE_VAL([db_cv_enable_command_$1], [db_cv_enable_command_$1=$2]))
  if test "[${db_cv_enable_command_$1}]" = yes; then
    AC_DEFINE_UNQUOTED([ENABLE_$3],[1],[whether to enable $4])
  fi
  AC_MSG_RESULT([$db_cv_enable_command_$1])
])

