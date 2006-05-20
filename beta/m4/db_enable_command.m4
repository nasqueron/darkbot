AC_DEFUN([DB_ENABLE_COMMAND],
[
  AC_MSG_CHECKING([whether to enable $1 command])
  AC_ARG_ENABLE([$1],
    AS_HELP_STRING([--enable-$1],[enable $1 command @<:@$2@:>@]),
    [db_cv_enable_command_$1=$enableval],
    AC_CACHE_VAL([db_cv_enable_command_$1], [db_cv_enable_command_$1=$2]))
  if test "[${db_cv_enable_command_$1}]" = yes; then
    AC_DEFINE_UNQUOTED([$3],[1],[whether to enable $1 command])
  fi
  AC_MSG_RESULT([$db_cv_enable_command_$1])
])
