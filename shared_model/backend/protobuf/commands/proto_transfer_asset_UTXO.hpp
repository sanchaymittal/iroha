//
// Created by sanchay on 31/7/18.
//

#ifndef IROHA_PROTO_TRANSFER_ASSET_UTXO_HPP
#define IROHA_PROTO_TRANSFER_ASSET_UTXO_HPP

#include "backend/protobuf/common_objects/trivial_proto.hpp"
#include "commands.pb.h"
#include "backend/protobuf/common_objects/amount.hpp"
#include "interfaces/commands/transfer_asset.hpp"

namespace shared_model {
    namespace proto {

        class TransferAsset final : public CopyableProto<interface::TransferAsset,
                iroha::protocol::Command,
                TransferAsset> {
        public:
            template <typename CommandType>
            explicit TransferAsset(CommandType &&command);

            TransferAsset(const TransferAsset &o);

            TransferAsset(TransferAsset &&o) noexcept;

            const interface::Amount &amount() const override;

            const interface::types::AssetIdType &assetId() const override;

            const interface::types::AccountIdType &srcAccountId() const override;

            const interface::types::AccountIdType &destAccountId() const override;

            const interface::types::DescriptionType &description() const override;

        private:
            // lazy
            template <typename Value>
            using Lazy = detail::LazyInitializer<Value>;

            const iroha::protocol::TransferAsset &transfer_asset_;

            const Lazy<proto::Amount> amount_;
        };

    }  // namespace proto
}  // namespace shared_model

#endif //IROHA_PROTO_TRANSFER_ASSET_UTXO_HPP
