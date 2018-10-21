// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: params.proto

#ifndef PROTOBUF_INCLUDED_params_2eproto
#define PROTOBUF_INCLUDED_params_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_params_2eproto 

namespace protobuf_params_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_params_2eproto
namespace exportParams {
class ExportParams;
class ExportParamsDefaultTypeInternal;
extern ExportParamsDefaultTypeInternal _ExportParams_default_instance_;
}  // namespace exportParams
namespace google {
namespace protobuf {
template<> ::exportParams::ExportParams* Arena::CreateMaybeMessage<::exportParams::ExportParams>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace exportParams {

// ===================================================================

class ExportParams : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:exportParams.ExportParams) */ {
 public:
  ExportParams();
  virtual ~ExportParams();

  ExportParams(const ExportParams& from);

  inline ExportParams& operator=(const ExportParams& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  ExportParams(ExportParams&& from) noexcept
    : ExportParams() {
    *this = ::std::move(from);
  }

  inline ExportParams& operator=(ExportParams&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const ExportParams& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ExportParams* internal_default_instance() {
    return reinterpret_cast<const ExportParams*>(
               &_ExportParams_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(ExportParams* other);
  friend void swap(ExportParams& a, ExportParams& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ExportParams* New() const final {
    return CreateMaybeMessage<ExportParams>(NULL);
  }

  ExportParams* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<ExportParams>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const ExportParams& from);
  void MergeFrom(const ExportParams& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ExportParams* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated float ArrayOfData = 4 [packed = true];
  int arrayofdata_size() const;
  void clear_arrayofdata();
  static const int kArrayOfDataFieldNumber = 4;
  float arrayofdata(int index) const;
  void set_arrayofdata(int index, float value);
  void add_arrayofdata(float value);
  const ::google::protobuf::RepeatedField< float >&
      arrayofdata() const;
  ::google::protobuf::RepeatedField< float >*
      mutable_arrayofdata();

  // int32 IntVal = 1;
  void clear_intval();
  static const int kIntValFieldNumber = 1;
  ::google::protobuf::int32 intval() const;
  void set_intval(::google::protobuf::int32 value);

  // float FloatVal = 2;
  void clear_floatval();
  static const int kFloatValFieldNumber = 2;
  float floatval() const;
  void set_floatval(float value);

  // @@protoc_insertion_point(class_scope:exportParams.ExportParams)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedField< float > arrayofdata_;
  mutable int _arrayofdata_cached_byte_size_;
  ::google::protobuf::int32 intval_;
  float floatval_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_params_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ExportParams

// int32 IntVal = 1;
inline void ExportParams::clear_intval() {
  intval_ = 0;
}
inline ::google::protobuf::int32 ExportParams::intval() const {
  // @@protoc_insertion_point(field_get:exportParams.ExportParams.IntVal)
  return intval_;
}
inline void ExportParams::set_intval(::google::protobuf::int32 value) {
  
  intval_ = value;
  // @@protoc_insertion_point(field_set:exportParams.ExportParams.IntVal)
}

// float FloatVal = 2;
inline void ExportParams::clear_floatval() {
  floatval_ = 0;
}
inline float ExportParams::floatval() const {
  // @@protoc_insertion_point(field_get:exportParams.ExportParams.FloatVal)
  return floatval_;
}
inline void ExportParams::set_floatval(float value) {
  
  floatval_ = value;
  // @@protoc_insertion_point(field_set:exportParams.ExportParams.FloatVal)
}

// repeated float ArrayOfData = 4 [packed = true];
inline int ExportParams::arrayofdata_size() const {
  return arrayofdata_.size();
}
inline void ExportParams::clear_arrayofdata() {
  arrayofdata_.Clear();
}
inline float ExportParams::arrayofdata(int index) const {
  // @@protoc_insertion_point(field_get:exportParams.ExportParams.ArrayOfData)
  return arrayofdata_.Get(index);
}
inline void ExportParams::set_arrayofdata(int index, float value) {
  arrayofdata_.Set(index, value);
  // @@protoc_insertion_point(field_set:exportParams.ExportParams.ArrayOfData)
}
inline void ExportParams::add_arrayofdata(float value) {
  arrayofdata_.Add(value);
  // @@protoc_insertion_point(field_add:exportParams.ExportParams.ArrayOfData)
}
inline const ::google::protobuf::RepeatedField< float >&
ExportParams::arrayofdata() const {
  // @@protoc_insertion_point(field_list:exportParams.ExportParams.ArrayOfData)
  return arrayofdata_;
}
inline ::google::protobuf::RepeatedField< float >*
ExportParams::mutable_arrayofdata() {
  // @@protoc_insertion_point(field_mutable_list:exportParams.ExportParams.ArrayOfData)
  return &arrayofdata_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace exportParams

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_params_2eproto
