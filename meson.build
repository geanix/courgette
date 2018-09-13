project('courgette', 'cpp', 'c')

#
# libevent
#
event_dirs = include_directories('base/third_party/libevent/compat', 'base/third_party/libevent/linux')
event_args = ['-DHAVE_CONFIG_H']
event_src = [
  'base/third_party/libevent/buffer.c',
  'base/third_party/libevent/evbuffer.c',
  'base/third_party/libevent/evdns.c',
  'base/third_party/libevent/event.c',
  'base/third_party/libevent/event_tagging.c',
  'base/third_party/libevent/evrpc.c',
  'base/third_party/libevent/evutil.c',
  'base/third_party/libevent/http.c',
  'base/third_party/libevent/log.c',
  'base/third_party/libevent/poll.c',
  'base/third_party/libevent/select.c',
  'base/third_party/libevent/signal.c',
  'base/third_party/libevent/strlcpy.c',
  'base/third_party/libevent/epoll.c',
]

event = static_library('event', event_src,
  include_directories : event_dirs,
  c_args : event_args,
)

#
# xdg_mime
#
xdg_mime_src = [
  'base/third_party/xdg_mime/xdgmime.c',
  'base/third_party/xdg_mime/xdgmimealias.c',
  'base/third_party/xdg_mime/xdgmimecache.c',
  'base/third_party/xdg_mime/xdgmimeglob.c',
  'base/third_party/xdg_mime/xdgmimeicon.c',
  'base/third_party/xdg_mime/xdgmimeint.c',
  'base/third_party/xdg_mime/xdgmimemagic.c',
  'base/third_party/xdg_mime/xdgmimeparent.c',
]
xdg_mime = static_library('xdg_mime', xdg_mime_src)

#
# xdg_user_dirs
#
xdg_user_dirs = static_library('xdg_user_dirs', 'base/third_party/xdg_user_dirs/xdg_user_dir_lookup.cc')

#
# base
#
cpp = meson.get_compiler('cpp')

base_dirs = include_directories('gen')
base_args = ['-include', 'build/config.h', '-Wno-non-virtual-dtor']
base_deps = [
  dependency('threads'),
  cpp.find_library('dl'),
]

base_src = [
  'base/allocator/allocator_check.cc',
  'base/allocator/allocator_extension.cc',
  'base/at_exit.cc',
  'base/barrier_closure.cc',
  'base/base64.cc',
  'base/base64url.cc',
  'base/big_endian.cc',
  'base/build_time.cc',
  'base/callback_helpers.cc',
  'base/callback_internal.cc',
  'base/command_line.cc',
  'base/cpu.cc',
  'base/observer_list_internal.cc',
  'base/observer_list_types.cc',
  'base/debug/activity_analyzer.cc',
  'base/debug/activity_tracker.cc',
  'base/debug/alias.cc',
  'base/debug/asan_invalid_access.cc',
  'base/debug/crash_logging.cc',
  'base/debug/debugger.cc',
  'base/debug/dump_without_crashing.cc',
  'base/debug/proc_maps_linux.cc',
  'base/debug/profiler.cc',
  'base/debug/stack_trace.cc',
  'base/debug/task_annotator.cc',
  'base/debug/thread_heap_usage_tracker.cc',
  'base/deferred_sequenced_task_runner.cc',
  'base/environment.cc',
  'base/feature_list.cc',
  'base/file_descriptor_store.cc',
  'base/files/file.cc',
  'base/files/file_enumerator.cc',
  'base/files/file_path.cc',
  'base/files/file_path_constants.cc',
  'base/files/file_path_watcher.cc',
  'base/files/file_path_watcher_linux.cc',
  'base/files/file_proxy.cc',
  'base/files/file_tracing.cc',
  'base/files/file_util.cc',
  'base/files/file_util_linux.cc',
  'base/files/important_file_writer.cc',
  'base/files/memory_mapped_file.cc',
  'base/files/scoped_file.cc',
  'base/files/scoped_temp_dir.cc',
  'base/guid.cc',
  'base/hash.cc',
  'base/json/json_file_value_serializer.cc',
  'base/json/json_parser.cc',
  'base/json/json_reader.cc',
  'base/json/json_string_value_serializer.cc',
  'base/json/json_value_converter.cc',
  'base/json/json_writer.cc',
  'base/json/string_escape.cc',
  'base/lazy_instance_helpers.cc',
  'base/linux_util.cc',
  'base/location.cc',
  'base/logging.cc',
  'base/md5.cc',
  'base/memory/aligned_memory.cc',
  'base/memory/discardable_memory.cc',
  'base/memory/discardable_memory_allocator.cc',
  'base/memory/discardable_shared_memory.cc',
  'base/memory/memory_coordinator_client.cc',
  'base/memory/memory_coordinator_client_registry.cc',
  'base/memory/memory_coordinator_proxy.cc',
  'base/memory/memory_pressure_listener.cc',
  'base/memory/memory_pressure_monitor.cc',
  'base/memory/platform_shared_memory_region.cc',
  'base/memory/protected_memory.cc',
  'base/memory/read_only_shared_memory_region.cc',
  'base/memory/ref_counted.cc',
  'base/memory/ref_counted_memory.cc',
  'base/memory/shared_memory_handle.cc',
  'base/memory/shared_memory_helper.cc',
  'base/memory/shared_memory_mapping.cc',
  'base/memory/shared_memory_tracker.cc',
  'base/memory/unsafe_shared_memory_region.cc',
  'base/memory/weak_ptr.cc',
  'base/memory/writable_shared_memory_region.cc',
  'base/message_loop/message_loop.cc',
  'base/message_loop/message_loop_current.cc',
  'base/message_loop/message_loop_task_runner.cc',
  'base/message_loop/message_pump.cc',
  'base/message_loop/message_pump_default.cc',
  'base/message_loop/pending_task_queue.cc',
  'base/metrics/bucket_ranges.cc',
  'base/metrics/dummy_histogram.cc',
  'base/metrics/field_trial.cc',
  'base/metrics/field_trial_param_associator.cc',
  'base/metrics/field_trial_params.cc',
  'base/metrics/histogram.cc',
  'base/metrics/histogram_base.cc',
  'base/metrics/histogram_delta_serialization.cc',
  'base/metrics/histogram_functions.cc',
  'base/metrics/histogram_samples.cc',
  'base/metrics/histogram_snapshot_manager.cc',
  'base/metrics/metrics_hashes.cc',
  'base/metrics/persistent_histogram_allocator.cc',
  'base/metrics/persistent_memory_allocator.cc',
  'base/metrics/persistent_sample_map.cc',
  'base/metrics/sample_map.cc',
  'base/metrics/sample_vector.cc',
  'base/metrics/single_sample_metrics.cc',
  'base/metrics/sparse_histogram.cc',
  'base/metrics/statistics_recorder.cc',
  'base/metrics/ukm_source_id.cc',
  'base/metrics/user_metrics.cc',
  'base/native_library.cc',
  'base/observer_list_threadsafe.cc',
  'base/path_service.cc',
  'base/pending_task.cc',
  'base/pickle.cc',
  'base/power_monitor/power_monitor.cc',
  'base/power_monitor/power_monitor_device_source.cc',
  'base/power_monitor/power_monitor_source.cc',
  'base/process/internal_linux.cc',
  'base/process/kill.cc',
  'base/process/launch.cc',
  'base/process/memory.cc',
  'base/process/memory_linux.cc',
  'base/process/process_handle.cc',
  'base/process/process_handle_linux.cc',
  'base/process/process_info_linux.cc',
  'base/process/process_iterator.cc',
  'base/process/process_iterator_linux.cc',
  'base/process/process_linux.cc',
  'base/process/process_metrics.cc',
  'base/process/process_metrics_linux.cc',
  'base/profiler/native_stack_sampler.cc',
  'base/profiler/stack_sampling_profiler.cc',
  'base/rand_util.cc',
  'base/run_loop.cc',
  'base/sampling_heap_profiler/lock_free_address_hash_set.cc',
  'base/sampling_heap_profiler/module_cache.cc',
  'base/sampling_heap_profiler/poisson_allocation_sampler.cc',
  'base/sampling_heap_profiler/sampling_heap_profiler.cc',
  'base/scoped_native_library.cc',
  'base/sequence_checker_impl.cc',
  'base/sequence_token.cc',
  'base/sequenced_task_runner.cc',
  'base/sha1.cc',
  'base/strings/latin1_string_conversions.cc',
  'base/strings/nullable_string16.cc',
  'base/strings/pattern.cc',
  'base/strings/safe_sprintf.cc',
  'base/strings/strcat.cc',
  'base/strings/string16.cc',
  'base/strings/string_number_conversions.cc',
  'base/strings/string_piece.cc',
  'base/strings/string_split.cc',
  'base/strings/string_util.cc',
  'base/strings/string_util_constants.cc',
  'base/strings/stringprintf.cc',
  'base/strings/utf_offset_string_conversions.cc',
  'base/strings/utf_string_conversion_utils.cc',
  'base/strings/utf_string_conversions.cc',
  'base/supports_user_data.cc',
  'base/synchronization/atomic_flag.cc',
  'base/synchronization/lock.cc',
  'base/sys_info.cc',
  'base/syslog_logging.cc',
  'base/system_monitor/system_monitor.cc',
  'base/task/cancelable_task_tracker.cc',
  'base/task/lazy_task_runner.cc',
  'base/task/post_task.cc',
  'base/task/scoped_set_task_priority_for_current_thread.cc',
  'base/task/sequence_manager/enqueue_order.cc',
  'base/task/sequence_manager/graceful_queue_shutdown_helper.cc',
  'base/task/sequence_manager/lazy_now.cc',
  'base/task/sequence_manager/real_time_domain.cc',
  'base/task/sequence_manager/sequence_manager.cc',
  'base/task/sequence_manager/sequence_manager_impl.cc',
  'base/task/sequence_manager/task_queue.cc',
  'base/task/sequence_manager/task_queue_impl.cc',
  'base/task/sequence_manager/task_queue_selector.cc',
  'base/task/sequence_manager/task_queue_task_runner.cc',
  'base/task/sequence_manager/thread_controller_impl.cc',
  'base/task/sequence_manager/thread_controller_with_message_pump_impl.cc',
  'base/task/sequence_manager/time_domain.cc',
  'base/task/sequence_manager/work_queue.cc',
  'base/task/sequence_manager/work_queue_sets.cc',
  'base/task/task_executor.cc',
  'base/task/task_scheduler/delayed_task_manager.cc',
  'base/task/task_scheduler/environment_config.cc',
  'base/task/task_scheduler/initialization_util.cc',
  'base/task/task_scheduler/priority_queue.cc',
  'base/task/task_scheduler/scheduler_lock_impl.cc',
  'base/task/task_scheduler/scheduler_single_thread_task_runner_manager.cc',
  'base/task/task_scheduler/scheduler_worker.cc',
  'base/task/task_scheduler/scheduler_worker_pool.cc',
  'base/task/task_scheduler/scheduler_worker_pool_impl.cc',
  'base/task/task_scheduler/scheduler_worker_pool_params.cc',
  'base/task/task_scheduler/scheduler_worker_stack.cc',
  'base/task/task_scheduler/sequence.cc',
  'base/task/task_scheduler/sequence_sort_key.cc',
  'base/task/task_scheduler/service_thread.cc',
  'base/task/task_scheduler/task.cc',
  'base/task/task_scheduler/task_scheduler.cc',
  'base/task/task_scheduler/task_scheduler_impl.cc',
  'base/task/task_scheduler/task_tracker.cc',
  'base/task/task_traits.cc',
  'base/task_runner.cc',
  'base/third_party/dmg_fp/dtoa_wrapper.cc',
  'base/third_party/dmg_fp/g_fmt.cc',
  'base/third_party/icu/icu_utf.cc',
  'base/third_party/nspr/prtime.cc',
  'base/third_party/superfasthash/superfasthash.c',
  'base/threading/platform_thread_linux.cc',
  'base/threading/post_task_and_reply_impl.cc',
  'base/threading/scoped_blocking_call.cc',
  'base/threading/sequence_local_storage_map.cc',
  'base/threading/sequence_local_storage_slot.cc',
  'base/threading/sequenced_task_runner_handle.cc',
  'base/threading/simple_thread.cc',
  'base/threading/thread.cc',
  'base/threading/thread_checker_impl.cc',
  'base/threading/thread_collision_warner.cc',
  'base/threading/thread_id_name_manager.cc',
  'base/threading/thread_local_storage.cc',
  'base/threading/thread_restrictions.cc',
  'base/threading/thread_task_runner_handle.cc',
  'base/threading/watchdog.cc',
  'base/time/clock.cc',
  'base/time/default_clock.cc',
  'base/time/default_tick_clock.cc',
  'base/time/tick_clock.cc',
  'base/time/time.cc',
  'base/time/time_override.cc',
  'base/time/time_to_iso8601.cc',
  'base/timer/elapsed_timer.cc',
  'base/timer/timer.cc',
  'base/trace_event/auto_open_close_event.cc',
  'base/trace_event/blame_context.cc',
  'base/trace_event/category_registry.cc',
  'base/trace_event/event_name_filter.cc',
  'base/trace_event/heap_profiler_allocation_context.cc',
  'base/trace_event/heap_profiler_allocation_context_tracker.cc',
  'base/trace_event/heap_profiler_event_filter.cc',
  'base/trace_event/malloc_dump_provider.cc',
  'base/trace_event/memory_allocator_dump.cc',
  'base/trace_event/memory_allocator_dump_guid.cc',
  'base/trace_event/memory_dump_manager.cc',
  'base/trace_event/memory_dump_provider_info.cc',
  'base/trace_event/memory_dump_request_args.cc',
  'base/trace_event/memory_dump_scheduler.cc',
  'base/trace_event/memory_infra_background_whitelist.cc',
  'base/trace_event/memory_usage_estimator.cc',
  'base/trace_event/process_memory_dump.cc',
  'base/trace_event/trace_buffer.cc',
  'base/trace_event/trace_config.cc',
  'base/trace_event/trace_config_category_filter.cc',
  'base/trace_event/trace_event_argument.cc',
  'base/trace_event/trace_event_filter.cc',
  'base/trace_event/trace_event_impl.cc',
  'base/trace_event/trace_event_memory_overhead.cc',
  'base/trace_event/trace_event_system_stats_monitor.cc',
  'base/trace_event/trace_log.cc',
  'base/trace_event/trace_log_constants.cc',
  'base/trace_event/tracing_agent.cc',
  'base/unguessable_token.cc',
  'base/value_conversions.cc',
  'base/value_iterators.cc',
  'base/values.cc',
  'base/version.cc',
  'base/vlog.cc',
]

base_src += [
  'base/debug/debugger_posix.cc',
  'base/debug/stack_trace_posix.cc',
  'base/files/file_descriptor_watcher_posix.cc',
  'base/files/file_enumerator_posix.cc',
  'base/files/file_posix.cc',
  'base/files/file_util_posix.cc',
  'base/files/memory_mapped_file_posix.cc',
  'base/memory/protected_memory_posix.cc',
  'base/message_loop/watchable_io_message_pump_posix.cc',
  'base/native_library_posix.cc',
  'base/posix/file_descriptor_shuffle.cc',
  'base/posix/global_descriptors.cc',
  'base/posix/safe_strerror.cc',
  'base/posix/unix_domain_socket.cc',
  'base/process/kill_posix.cc',
  'base/process/launch_posix.cc',
  'base/process/process_handle_posix.cc',
  'base/process/process_metrics_posix.cc',
  'base/process/process_posix.cc',
  'base/profiler/native_stack_sampler_posix.cc',
  'base/rand_util_posix.cc',
  'base/sampling_heap_profiler/module_cache_posix.cc',
  'base/strings/sys_string_conversions_posix.cc',
  'base/sync_socket_posix.cc',
  'base/synchronization/condition_variable_posix.cc',
  'base/synchronization/lock_impl_posix.cc',
  'base/synchronization/waitable_event_posix.cc',
  'base/synchronization/waitable_event_watcher_posix.cc',
  'base/sys_info_posix.cc',
  'base/task/task_scheduler/task_tracker_posix.cc',
  'base/threading/platform_thread_internal_posix.cc',
  'base/threading/platform_thread_posix.cc',
  'base/threading/thread_local_storage_posix.cc',
  'base/timer/hi_res_timer_manager_posix.cc',
]

base_src += [
  'base/base_paths.cc',
  'base/metrics/persistent_histogram_storage.cc',
  'base/base_paths_posix.cc',
  'base/debug/elf_reader_linux.cc',
]

base_src += [
  'base/nix/mime_util_xdg.cc',
  'base/nix/xdg_util.cc',
  'base/sys_info_linux.cc',
]

base_src += [
  'base/linux_util.cc',
]

base_src += [
  'base/base_switches.cc',
]

base_src += [
  'base/message_loop/message_pump_libevent.cc',
  'base/message_loop/message_pump_libevent.h',
  'base/memory/platform_shared_memory_region_posix.cc',
  'base/memory/shared_memory_handle_posix.cc',
  'base/memory/shared_memory_posix.cc',
  'base/time/time_conversion_posix.cc',
  'base/time/time_exploded_posix.cc',
  'base/time/time_now_posix.cc',
]

base_src += [
  'base/power_monitor/power_monitor_device_source_stub.cc',
]

base_src += [
  'third_party/modp_b64/modp_b64.cc'
]

base = library('chromium', base_src,
  cpp_args : base_args,
  link_with : [event, xdg_mime, xdg_user_dirs],
  dependencies : base_deps,
  include_directories : base_dirs,
  install : true,
  version : '0.0.1',
)

find = find_program('find')
base_subdirs = ['/', '/numerics', '/task', '/i18n', '/threading',
            '/nix', '/sampling_heap_profiler', '/power_monitor',
            '/posix', '/system_monitor', '/profiler', '/metrics',
            '/debug', '/files', '/memory', '/trace_event',
            '/timer', '/synchronization', '/message_loop', '/strings',
            '/json', '/containers', '/allocator', '/process',
            '/test', '/time']
foreach base_sd : base_subdirs
  base_headers = run_command(find,
    ['@0@/base@1@'.format(meson.source_root(), base_sd),
     '-maxdepth', '1', '-name', '*.h']
  )
  install_headers(base_headers.stdout().split(), subdir : 'chromium/base@0@'.format(base_sd))
endforeach
install_headers('build/buildflag.h', 'build/build_config.h', 'build/config.h', subdir : 'chromium/build')
install_subdir('gen/base', install_dir : 'include/chromium')

#
# lzma_sdk
#
lzma_args = [
  '-Wno-self-assign',
  '-D_7ZIP_ST',
  '-D_7Z_NO_METHODS_FILTERS',
  '-D_LZMA_PROB32',
]
lzma_src = [
  'third_party/lzma_sdk/7zAlloc.c',
  'third_party/lzma_sdk/7zArcIn.c',
  'third_party/lzma_sdk/7zBuf.c',
  'third_party/lzma_sdk/7zCrc.c',
  'third_party/lzma_sdk/7zCrcOpt.c',
  'third_party/lzma_sdk/7zDec.c',
  'third_party/lzma_sdk/7zFile.c',
  'third_party/lzma_sdk/7zStream.c',
  'third_party/lzma_sdk/Alloc.c',
  'third_party/lzma_sdk/Bcj2.c',
  'third_party/lzma_sdk/Bra.c',
  'third_party/lzma_sdk/Bra86.c',
  'third_party/lzma_sdk/CpuArch.c',
  'third_party/lzma_sdk/Delta.c',
  'third_party/lzma_sdk/LzFind.c',
  'third_party/lzma_sdk/Lzma2Dec.c',
  'third_party/lzma_sdk/LzmaDec.c',
  'third_party/lzma_sdk/LzmaEnc.c',
  'third_party/lzma_sdk/LzmaLib.c',
]

lzma = static_library('lzma', lzma_src,
  c_args : lzma_args,
)

#
# divsufsort
#
divsufsort_src = [
  'courgette/third_party/divsufsort/divsufsort.cc',
  'courgette/third_party/divsufsort/sssort.cc',
  'courgette/third_party/divsufsort/trsort.cc',
]
divsufsort = static_library('divsufsort', divsufsort_src)

#
# bsdiff
#
bsdiff_src = [
  'courgette/third_party/bsdiff/bsdiff_apply.cc',
  'courgette/third_party/bsdiff/bsdiff_create.cc',
]
bsdiff = static_library('bsdiff', bsdiff_src)

#
# courgette
#
courgette_common_src = [
  'courgette/crc.cc',
  'courgette/memory_allocator.cc',
  'courgette/streams.cc',
]

courgette_common = static_library('courgette_common', courgette_common_src,
  link_with : [base, lzma],
)

courgette_args = ['-Wno-non-virtual-dtor']
courgette_src = [
  'courgette/adjustment_method.cc',
  'courgette/adjustment_method_2.cc',
  'courgette/assembly_program.cc',
  'courgette/courgette_flow.cc',
  'courgette/difference_estimator.cc',
  'courgette/disassembler.cc',
  'courgette/disassembler_elf_32.cc',
  'courgette/disassembler_elf_32_arm.cc',
  'courgette/disassembler_elf_32_x86.cc',
  'courgette/disassembler_win32.cc',
  'courgette/disassembler_win32_x64.cc',
  'courgette/disassembler_win32_x86.cc',
  'courgette/encoded_program.cc',
  'courgette/ensemble.cc',
  'courgette/ensemble_apply.cc',
  'courgette/ensemble_create.cc',
  'courgette/label_manager.cc',
  'courgette/program_detector.cc',
  'courgette/rel32_finder.cc',
  'courgette/rel32_finder_x64.cc',
  'courgette/rel32_finder_x86.cc',
  'courgette/simple_delta.cc',
]

install_headers('courgette/courgette.h', subdir : 'chromium/courgette')

courgette = library('courgette', courgette_src,
  link_with : [base, courgette_common, bsdiff, divsufsort],
  cpp_args : courgette_args,
  install : true,
  version : '0.0.1',
)

executable('courgette_minimal_tool', 'courgette/courgette_minimal_tool.cc',
  link_with : courgette,
  install : true,
)

executable('courgette', 'courgette/courgette_tool.cc',
  link_with : [base, courgette],
  install : true,
)
