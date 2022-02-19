// Copyright (c) Microsoft Corporation. All rights reserved.
// SPDX-License-Identifier: MIT

/**
 * @brief Azure::Core::Json::_internal::json Deserialization support functions.
 *
 * This file contains a set of support functions to aid in serializing and deserializing JSON
 * objects. It also contains Deserializer classes, one for each model type which each support a
 * static Serialize and Deserialize function which serialize and deserialize the specified model
 * types from and to JSON objects.
 *
 */

#pragma once

#include "attestation_client_models_private.hpp"
#include "azure/attestation/attestation_client.hpp"
#include "azure/attestation/attestation_client_models.hpp"
#include <azure/core/internal/json/json.hpp>
#include <memory>
#include <string>

// cspell: words jwks MrSigner MrEnclave
namespace Azure { namespace Security { namespace Attestation { namespace _detail {

  /***************************************
   * A quick note on the naming convention for the Serialize/Deserialize classes.
   *
   * Serialization classes are named "XxxxSerializer". They contain one or two static methods named
   * "Serialize" and "Deserialize".
   *
   * The Serialize method takes an instance of an "Xxxx" object and returns a std::string which
   * represents the Xxxx object serialized into JSON.
   *
   * The Deserialize method takes an instance of a json object and returns an instance of the Xxxx
   * type.
   *
   */

  struct OpenIdMetadataSerializer final
  {
    static Models::AttestationOpenIdMetadata Deserialize(
        std::unique_ptr<Azure::Core::Http::RawResponse>& response);
  };

  struct AttestSgxEnclaveRequestSerializer final
  {
    static std::string Serialize(
        Azure::Security::Attestation::Models::_detail::AttestSgxEnclaveRequest const& request);
  };

  struct AttestOpenEnclaveRequestSerializer final
  {
    static std::string Serialize(
        Azure::Security::Attestation::Models::_detail::AttestOpenEnclaveRequest const& request);
  };

  struct AttestationServiceTokenResponseSerializer final
  {
    static std::string Deserialize(Azure::Core::Json::_internal::json const& parsedBody);
    static std::string Deserialize(std::unique_ptr<Azure::Core::Http::RawResponse>& response);
  };

  struct AttestationResultSerializer final
  {
  public:
    static Models::AttestationResult Deserialize(
        Azure::Core::Json::_internal::json const& parsedJson);
  };

  struct JsonWebKeySerializer final
  {
    static Models::_detail::JsonWebKey Deserialize(const Azure::Core::Json::_internal::json& jwk);
  };

  // cspell: words jwks
  struct JsonWebKeySetSerializer final
  {
    static Azure::Security::Attestation::Models::_detail::JsonWebKeySet Deserialize(
        std::unique_ptr<Azure::Core::Http::RawResponse>& response);
    static Azure::Security::Attestation::Models::_detail::JsonWebKeySet Deserialize(
        const Azure::Core::Json::_internal::json& jwk);
  };

  /**
   * @brief Serializer/Deserializer for RFC 7515/7517 JSON Web Token/JSON Web SIgnature header
   * objects.
   *
   */
  struct AttestationTokenHeaderSerializer final
  {
    static Models::AttestationTokenHeader Deserialize(
        Azure::Core::Json::_internal::json const& jsonHeader);
    static std::string Serialize(Models::AttestationTokenHeader const& tokenHeader);
  };

}}}} // namespace Azure::Security::Attestation::_detail