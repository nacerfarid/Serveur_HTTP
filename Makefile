all: sortiehttp

sortiehttp: main.o parseur.o ajout_fichier.o ajout_langages.o ajout_methodes.o ajoutDate.o ajoutServeur.c cb_truc.o compare.o concat_chaine.o config_init.o create_res.o fonction3.o fonction4.o fonction56.o fonctionx.o ajoutMessageCode.o norm_URL.o recup_ext.o recup_fichier.o remplissageStruct.o semantique.o suppr_fichier.o suppr_langages.o suppr_methodes.o verifAccept.o verifLang.o ecrase_fichier.o est_absolute_form.o est_absolute_path.o est_absolute_uri.o est_accept.o est_acceptable_ranges.o est_accept_charset.o est_accept_charset_header.o est_accept_encoding.o est_accept_encoding_header.o est_accept_ext.o est_accept_header.o est_accept_language.o est_accept_language_header.o est_accept_params.o est_accept_ranges.o est_age.o est_age_header.o est_allow.o est_alpha.o est_alphanum.o est_asctime_date.o est_asterisk_form.o est_authority.o est_authority_form.o est_authorization.o est_authorization_header.o est_auth_param.o est_auth_scheme.o est_byte_content_range.o est_byte_range.o est_byte_range_resp.o est_byte_range_set.o est_byte_range_spec.o est_byte_ranges_specifier.o est_bytes_unit.o est_cache_control.o est_cache_control_header.o est_cache_directive.o est_challenge.o est_char.o est_charset.o est_chunk.o est_chunk_data.o est_chunked_body.o est_chunk_ext.o est_chunk_ext_name.o est_chunk_ext_val.o est_chunk_size.o est_codings.o est_comment.o est_complete_length.o est_connection.o est_connection_header.o est_connection_option.o est_content_coding.o est_content_encoding.o est_content_language.o est_content_length.o est_content_length_header.o est_content_location.o est_content_range.o est_content_type.o est_cookie_pair.o est_cookie_name.o est_cookie_value.o est_cookie_octet.o est_cookie_header.o est_cookie_string.o est_credentials.o est_crlf.o est_ctext.o est_date.o est_date1.o est_date2.o est_date3.o est_date_header.o est_day.o est_day_name.o est_day_name_l.o est_dec_octet.o est_delay_seconds.o est_delta_seconds.o est_digit.o est_dquote.o est_entity_tag.o est_etag.o est_etagc.o est_expect.o est_expect_header.o est_expires.o est_expires_header.o est_extension.o est_extension_pragma.o est_extlang.o est_field_content.o est_field_name.o est_field_value.o est_field_vchar.o est_first_byte_pos.o est_fragment.o est_gen_delims.o est_gmt.o est_grandfathered.o est_h16.o est_header_field.o est_hexdig.o est_hier_part.o est_host.o est_Host.o est_host_header.o est_hour.o est_http_date.o est_http_message.o est_http_name.o est_https_uri.o est_http_uri.o est_http_version.o est_if_match.o est_if_match_header.o est_if_modified_since.o est_if_modified_since_header.o est_if_none_match.o est_if_none_match_header.o est_if_range.o est_if_range_header.o est_if_unmodified_since.o est_if_unmodified_since_header.o est_imf_fixdate.o est_ip_literal.o est_ipv4address.o est_ipv6address.o est_ipvfuture.o est_irregular.o est_langtag.o est_language.o est_language_range.o est_language_tag.o est_last_byte_pos.o est_last_chunk.o est_last_modified.o est_location.o est_location_header.o est_ls32.o est_max_forwards.o est_max_forwards_header.o est_media_range.o est_media_type.o est_message_body.o est_method.o est_minute.o est_month.o est_obs_date.o est_obs_fold.o est_obs_text.o est_opaque_tag.o est_origin_form.o est_other_content_range.o est_other_range_resp.o est_other_range_set.o est_other_range_unit.o est_other_ranges_specifier.o est_parameter.o est_partial_uri.o est_path.o est_path_abempty.o est_path_absolute.o est_path_empty.o est_path_noscheme.o est_path_rootless.o est_pchar.o est_pct_encoded.o est_port.o est_pragma.o est_pragma_directive.o est_pragma_header.o est_privateuse.o est_product.o est_product_version.o est_protocol.o est_protocol_name.o est_protocol_version.o est_proxy_authenticate.o est_proxy_authorization.o est_proxy_authorization_header.o est_pseudonym.o est_qdtext.o est_query.o est_quoted_pair.o est_quoted_string.o est_qvalue.o est_range.o est_range_header.o est_range_unit.o est_rank.o est_reason_phrase.o est_received_by.o est_received_protocol.o est_referer.o est_referer_header.o est_region.o est_reg_name.o est_regular.o est_relative_part.o est_relative_ref.o est_request_line.o est_request_target.o est_reserved.o est_retry_after.o est_retry_after_header.o est_rfc850_date.o est_scheme.o est_script.o est_second.o est_segment.o est_segment_nz.o est_segment_nz_nc.o est_server.o est_singleton.o est_start_line.o est_status_code.o est_status_line.o est_sub_delims.o est_subtype.o est_suffix_byte_range_spec.o est_suffix_length.o est_tchar.o est_t_codings.o est_te.o est_te_header.o est_time_of_day.o est_token.o est_token68.o est_trailer.o est_trailer_header.o est_trailer_part.o est_t_ranking.o est_transfer_coding.o est_transfer_encoding.o est_transfer_encoding_header.o est_transfer_extension.o est_transfer_parameter.o est_type.o est_unreserved.o est_unsatisfied_range.o est_upgrade.o est_upgrade_header.o est_uri.o est_uri_host.o est_uri_reference.o est_user_agent.o est_user_agent_header.o est_userinfo.o est_variant.o est_vary.o est_vary_header.o est_vchar.o est_via.o est_via_header.o est_warn_agent.o est_warn_code.o est_warn_date.o est_warning.o est_warning_header.o est_warn_text.o est_warning_value.o est_weak.o est_weight.o est_www_authenticate.o est_year.o bissextile.o ajoutLocation.o test.o itoa.o ajoutContentLength.o ajoutContentType.o librequest.so
	gcc -o sortiehttp main.o parseur.o ajout_fichier.o ajout_langages.o ajout_methodes.o ajoutDate.o ajoutServeur.c cb_truc.o compare.o concat_chaine.o config_init.o create_res.o fonction3.o fonction4.o fonction56.o fonctionx.o ajoutMessageCode.o norm_URL.o recup_ext.o recup_fichier.o remplissageStruct.o semantique.o suppr_fichier.o suppr_langages.o suppr_methodes.o verifAccept.o verifLang.o ecrase_fichier.o est_absolute_form.o est_absolute_path.o est_absolute_uri.o est_accept.o est_acceptable_ranges.o est_accept_charset.o est_accept_charset_header.o est_accept_encoding.o est_accept_encoding_header.o est_accept_ext.o est_accept_header.o est_accept_language.o est_accept_language_header.o est_accept_params.o est_accept_ranges.o est_age.o est_age_header.o est_allow.o est_alpha.o est_alphanum.o est_asctime_date.o est_asterisk_form.o est_authority.o est_authority_form.o est_authorization.o est_authorization_header.o est_auth_param.o est_auth_scheme.o est_byte_content_range.o est_byte_range.o est_byte_range_resp.o est_byte_range_set.o est_byte_range_spec.o est_byte_ranges_specifier.o est_bytes_unit.o est_cache_control.o est_cache_control_header.o est_cache_directive.o est_challenge.o est_char.o est_charset.o est_chunk.o est_chunk_data.o est_chunked_body.o est_chunk_ext.o est_chunk_ext_name.o est_chunk_ext_val.o est_chunk_size.o est_codings.o est_comment.o est_complete_length.o est_connection.o est_connection_header.o est_connection_option.o est_content_coding.o est_content_encoding.o est_content_language.o est_content_length.o est_content_length_header.o est_content_location.o est_content_range.o est_content_type.o est_cookie_pair.o est_cookie_name.o est_cookie_value.o est_cookie_octet.o est_cookie_header.o est_cookie_string.o est_credentials.o est_crlf.o est_ctext.o est_date.o est_date1.o est_date2.o est_date3.o est_date_header.o est_day.o est_day_name.o est_day_name_l.o est_dec_octet.o est_delay_seconds.o est_delta_seconds.o est_digit.o est_dquote.o est_entity_tag.o est_etag.o est_etagc.o est_expect.o est_expect_header.o est_expires.o est_expires_header.o est_extension.o est_extension_pragma.o est_extlang.o est_field_content.o est_field_name.o est_field_value.o est_field_vchar.o est_first_byte_pos.o est_fragment.o est_gen_delims.o est_gmt.o est_grandfathered.o est_h16.o est_header_field.o est_hexdig.o est_hier_part.o est_host.o est_Host.o est_host_header.o est_hour.o est_http_date.o est_http_message.o est_http_name.o est_https_uri.o est_http_uri.o est_http_version.o est_if_match.o est_if_match_header.o est_if_modified_since.o est_if_modified_since_header.o est_if_none_match.o est_if_none_match_header.o est_if_range.o est_if_range_header.o est_if_unmodified_since.o est_if_unmodified_since_header.o est_imf_fixdate.o est_ip_literal.o est_ipv4address.o est_ipv6address.o est_ipvfuture.o est_irregular.o est_langtag.o est_language.o est_language_range.o est_language_tag.o est_last_byte_pos.o est_last_chunk.o est_last_modified.o est_location.o est_location_header.o est_ls32.o est_max_forwards.o est_max_forwards_header.o est_media_range.o est_media_type.o est_message_body.o est_method.o est_minute.o est_month.o est_obs_date.o est_obs_fold.o est_obs_text.o est_opaque_tag.o est_origin_form.o est_other_content_range.o est_other_range_resp.o est_other_range_set.o est_other_range_unit.o est_other_ranges_specifier.o est_parameter.o est_partial_uri.o est_path.o est_path_abempty.o est_path_absolute.o est_path_empty.o est_path_noscheme.o est_path_rootless.o est_pchar.o est_pct_encoded.o est_port.o est_pragma.o est_pragma_directive.o est_pragma_header.o est_privateuse.o est_product.o est_product_version.o est_protocol.o est_protocol_name.o est_protocol_version.o est_proxy_authenticate.o est_proxy_authorization.o est_proxy_authorization_header.o est_pseudonym.o est_qdtext.o est_query.o est_quoted_pair.o est_quoted_string.o est_qvalue.o est_range.o est_range_header.o est_range_unit.o est_rank.o est_reason_phrase.o est_received_by.o est_received_protocol.o est_referer.o est_referer_header.o est_region.o est_reg_name.o est_regular.o est_relative_part.o est_relative_ref.o est_request_line.o est_request_target.o est_reserved.o est_retry_after.o est_retry_after_header.o est_rfc850_date.o est_scheme.o est_script.o est_second.o est_segment.o est_segment_nz.o est_segment_nz_nc.o est_server.o est_singleton.o est_start_line.o est_status_code.o est_status_line.o est_sub_delims.o est_subtype.o est_suffix_byte_range_spec.o est_suffix_length.o est_tchar.o est_t_codings.o est_te.o est_te_header.o est_time_of_day.o est_token.o est_token68.o est_trailer.o est_trailer_header.o est_trailer_part.o est_t_ranking.o est_transfer_coding.o est_transfer_encoding.o est_transfer_encoding_header.o est_transfer_extension.o est_transfer_parameter.o est_type.o est_unreserved.o est_unsatisfied_range.o est_upgrade.o est_upgrade_header.o est_uri.o est_uri_host.o est_uri_reference.o est_user_agent.o est_user_agent_header.o est_userinfo.o est_variant.o est_vary.o est_vary_header.o est_vchar.o est_via.o est_via_header.o est_warn_agent.o est_warn_code.o est_warn_date.o est_warning.o est_warning_header.o est_warn_text.o est_warning_value.o est_weak.o est_weight.o est_www_authenticate.o est_year.o bissextile.o ajoutLocation.o test.o itoa.o ajoutContentType.o ajoutContentLength.o librequest.so 
config_init.o: config_init.c
	gcc -c config_init.c
parseur.o: parseur.c est_http_message.c
	gcc -c parseur.c est_http_message.c
semantique.o: semantique.c parseur.c est_connection_restr.c est_day_restr.c est_date1_restr.c est_hour_restr.c est_method_restr.c est_minute_restr.c est_second_restr.c est_pragma_restr.c
	gcc -c semantique.c parseur.c est_connection_restr.c est_day_restr.c est_date1_restr.c est_hour_restr.c est_method_restr.c est_minute_restr.c est_second_restr.c est_pragma_restr.c
norm_URL.o: norm_URL.c
	gcc -c norm_URL.c
cb_truc.o: cb_truc.c est_method.c est_cookie_string.c est_content_length.c est_transfer_encoding.c est_host.c est_referer.c est_user_agent.c est_accept.c est_accept_encoding.c est_connection.c
	gcc -c cb_truc.c est_method.c est_cookie_string.c est_content_length.c est_transfer_encoding.c est_host.c est_referer.c est_user_agent.c est_accept.c est_accept_encoding.c est_connection.c
remplissageStruct.o: remplissageStruct.c parseur.c cb_truc.c
	gcc -c remplissageStruct.c parseur.c cb_truc.c
fonctionx.o: fonctionx.c fonction3.c fonction4.c fonction56.c
	gcc -c fonctionx.c fonction3.c fonction4.c fonction56.c
ajout_fichier.o: ajout_fichier.c
	gcc -c ajout_fichier.c
recup_fichier.o: recup_fichier.c
	gcc -c recup_fichier.c
suppr_fichier.o: suppr_fichier.c
	gcc -c suppr_fichier.c
ajoutDate.o: ajoutDate.c
	gcc -c ajoutDate.c
ajoutServeur.o: ajoutServeur.c
	gcc -c ajoutServeur.c
ajoutMessageCode.o: ajoutMessageCode.c
	gcc -c ajoutMessageCode.c
create_res.o: create_res.c concat_chaine.c itoa.c
	gcc -c create_res.c concat_chaine.c itoa.c
recup_ext.o: recup_ext.c
	gcc -c recup_ext.c
suppr_langages.o: suppr_langages.c
	gcc -c suppr_langages.c
verifAccept.o: verifAccept.c
	gcc -c verifAccept.c
verifLang.o: verifLang.c
	gcc -c verifLang.c
compare.o: compare.c
	gcc -c compare.c
itoa.o: itoa.c
	gcc -c itoa.c
ajout_langages.o: ajout_langages.c
	gcc -c ajout_langages.c
ajout_methodes.o: ajout_methodes.c
	gcc -c ajout_methodes.c
est_connection_restr.o: est_connection_restr.c
	gcc -c est_connection_restr.c
est_day_restr.o: est_day_restr.c est_day.c
	gcc -c est_day_restr.c est_day.c
est_date1_restr.o: est_date1_restr.c bissextile.c est_year.c est_date1.c est_month.c est_day.c 
	gcc -c est_date1_restr.c bissextile.c est_year.c est_date1.c est_month.c est_day.c 
est_hour_restr.o: est_hour_restr.c est_hour.c
	gcc -c est_hour_restr.c est_hour.c
est_method_restr.o: est_method_restr.c est_method.c
	gcc -c est_method_restr.c est_method.c
est_minute_restr.o: est_minute_restr.c est_minute.c
	gcc -c est_minute_restr.c est_minute.c
est_second_restr.o: est_second_restr.c est_second.c
	gcc -c est_second_restr.c est_second.c
est_pragma_restr.o: est_pragma_restr.c est_pragma.c
	gcc -c est_pragma_restr.c est_pragma.c
fonction3.o: fonction3.c
	gcc -c fonction3.c
fonction4.o: fonction4.c
	gcc -c fonction4.c
fonction56.o: fonction56.c
	gcc -c fonction56.c
ajoutLocation.o: ajoutLocation.c
	gcc -c ajoutLocation.c
concat_chaine.o: concat_chaine.c
	gcc -c concat_chaine.c
ecrase_fichier.o: ecrase_fichier.c
	gcc -c ecrase_fichier.c
suppr_methodes.o:suppr_methodes.c
	gcc -c suppr_methodes.c
bissextile.o: bissextile.c
	gcc -c bissextile.c
est_absolute_form.o: est_absolute_form.c est_absolute_uri.c
	gcc -c est_absolute_form.c est_absolute_uri.c
est_absolute_path.o: est_absolute_path.c est_segment.c
	gcc -c est_absolute_path.c est_segment.c
est_absolute_uri.o: est_absolute_uri.c est_absolute_path.c est_query.c
	gcc -c est_absolute_uri.c est_absolute_path.c est_query.c
est_accept.o: est_accept.c est_media_range.c est_accept_params.c est_weight.c
	gcc -c est_accept.c est_media_range.c est_accept_params.c est_weight.c
est_acceptable_ranges.o: est_acceptable_ranges.c est_range_unit.c
	gcc -c est_acceptable_ranges.c est_range_unit.c
est_accept_charset.o: est_accept_charset.c est_charset.c est_weight.c
	gcc -c est_accept_charset.c est_charset.c est_weight.c
est_accept_charset_header.o: est_accept_charset_header.c est_accept_charset.c
	gcc -c est_accept_charset_header.c est_accept_charset.c
est_accept_encoding.o: est_accept_encoding.c est_codings.c est_weight.c
	gcc -c est_accept_encoding.c est_codings.c est_weight.c
est_accept_encoding_header.o: est_accept_encoding_header.c est_accept_encoding.c
	gcc -c est_accept_encoding_header.c est_accept_encoding.c
est_accept_ext.o: est_accept_ext.c est_token.c est_quoted_string.c
	gcc -c est_accept_ext.c est_token.c est_quoted_string.c
est_accept_header.o: est_accept_header.c est_accept.c
	gcc -c est_accept_header.c est_accept.c
est_accept_language.o: est_accept_language.c est_language_range.c est_weight.c
	gcc -c est_accept_language.c est_language_range.c est_weight.c
est_accept_language_header.o: est_accept_language_header.c est_accept_language.c
	gcc -c est_accept_language_header.c est_accept_language.c
est_accept_params.o: est_accept_params.c est_token.c est_weight.c
	gcc -c est_accept_params.c est_token.c est_weight.c
est_accept_ranges.o: est_accept_ranges.c est_acceptable_ranges.c
	gcc -c est_accept_ranges.c est_acceptable_ranges.c
est_age.o: est_age.c est_delta_seconds.c
	gcc -c est_age.c est_delta_seconds.c
est_age_header.o: est_age_header.c est_age.c
	gcc -c est_age_header.c est_age.c
est_allow.o: est_allow.c est_method.c
	gcc -c est_allow.c est_method.c
est_alpha.o: est_alpha.c
	gcc -c est_alpha.c
est_alphanum.o: est_alphanum.c est_alpha.c est_digit.c
	gcc -c est_alphanum.c est_alpha.c est_digit.c
est_asctime_date.o: est_asctime_date.c est_day_name.c est_date3.c est_time_of_day.c est_year.c est_gmt.c
	gcc -c est_asctime_date.c est_day_name.c est_date3.c est_time_of_day.c est_year.c est_gmt.c
est_asterisk_form.o: est_asterisk_form.c
	gcc -c est_asterisk_form.c
est_authority.o: est_authority.c est_host.c est_userinfo.c est_port.c
	gcc -c est_authority.c est_host.c est_userinfo.c est_port.c
est_authority_form.o: est_authority_form.c est_authority.c
	gcc -c est_authority_form.c est_authority.c
est_authorization.o: est_authorization.c est_credentials.c
	gcc -c est_authorization.c est_credentials.c
est_authorization_header.o: est_authorization_header.c est_authorization.c
	gcc -c est_authorization_header.c est_authorization.c
est_auth_param.o: est_auth_param.c est_transfer_parameter.c
	gcc -c est_auth_param.c est_transfer_parameter.c
est_auth_scheme.o: est_auth_scheme.c est_token.c
	gcc -c est_auth_scheme.c est_token.c
est_byte_content_range.o: est_byte_content_range.c est_bytes_unit.c est_byte_range_resp.c est_unsatisfied_range.c
	gcc -c est_byte_content_range.c est_bytes_unit.c est_byte_range_resp.c est_unsatisfied_range.c
est_byte_range.o: est_byte_range.c est_first_byte_pos.c est_last_byte_pos.c
	gcc -c est_byte_range.c est_first_byte_pos.c est_last_byte_pos.c
est_byte_range_resp.o: est_byte_range_resp.c est_asterisk_form.c est_complete_length.c est_byte_range.c
	gcc -c est_byte_range_resp.c est_asterisk_form.c est_complete_length.c est_byte_range.c
est_byte_range_set.o: est_byte_range_set.c est_byte_range_spec.c est_suffix_byte_range_spec.c
	gcc -c est_byte_range_set.c est_byte_range_spec.c est_suffix_byte_range_spec.c
est_byte_range_spec.o: est_byte_range_spec.c est_first_byte_pos.c est_last_byte_pos.c
	gcc -c est_byte_range_spec.c est_first_byte_pos.c est_last_byte_pos.c
est_byte_ranges_specifier.o: est_byte_ranges_specifier.c est_byte_range_set.c est_bytes_unit.c
	gcc -c est_byte_ranges_specifier.c est_byte_range_set.c est_bytes_unit.c
est_bytes_unit.o: est_bytes_unit.c
	gcc -c est_bytes_unit.c
est_cache_control.o: est_cache_control.c est_cache_directive.c
	gcc -c est_cache_control.c est_cache_directive.c
est_cache_control_header.o: est_cache_control_header.c est_cache_control.c
	gcc -c est_cache_control_header.c est_cache_control.c
est_cache_directive.o: est_cache_directive.c est_token.c est_chunk_ext_val.c
	gcc -c est_cache_directive.c est_token.c est_chunk_ext_val.c
est_challenge.o: est_challenge.c est_t_codings.c est_auth_scheme.c est_auth_param.c est_token68.c
	gcc -c est_challenge.c est_t_codings.c est_auth_scheme.c est_auth_param.c est_token68.c
est_char.o: est_char.c
	gcc -c est_char.c
est_charset.o: est_charset.c est_token.c
	gcc -c est_charset.c est_token.c
est_chunk.o: est_chunk.c est_chunk_size.c est_chunk_data.c est_chunk_ext.c
	gcc -c est_chunk.c est_chunk_size.c est_chunk_data.c est_chunk_ext.c
est_chunk_data.o: est_chunk_data.c
	gcc -c est_chunk_data.c
est_chunked_body.o: est_chunked_body.c est_last_chunk.c est_chunk.c est_chunk_data.c
	gcc -c est_chunked_body.c est_last_chunk.c est_chunk.c est_chunk_data.c
est_chunk_ext.o: est_chunk_ext.c est_chunk_ext_name.c est_chunk_ext_val.c
	gcc -c est_chunk_ext.c est_chunk_ext_name.c est_chunk_ext_val.c
est_chunk_ext_name.o: est_chunk_ext_name.c est_token.c
	gcc -c est_chunk_ext_name.c est_token.c
est_chunk_ext_val.o: est_chunk_ext_val.c est_token.c est_quoted_string.c
	gcc -c est_chunk_ext_val.c est_token.c est_quoted_string.c
est_chunk_size.o: est_chunk_size.c est_hexdig.c
	gcc -c est_chunk_size.c est_hexdig.c
est_codings.o: est_codings.c est_content_coding.c
	gcc -c est_codings.c est_content_coding.c
est_comment.o: est_comment.c est_quoted_pair.c est_ctext.c
	gcc -c est_comment.c est_quoted_pair.c est_ctext.c
est_complete_length.o: est_complete_length.c est_digit.c
	gcc -c est_complete_length.c est_digit.c
est_connection.o: est_connection.c est_connection_option.c
	gcc -c est_connection.c est_connection_option.c
est_connection_header.o: est_connection_header.c est_connection.c
	gcc -c est_connection_header.c est_connection.c
est_connection_option.o: est_connection_option.c est_token.c
	gcc -c est_connection_option.c est_token.c
est_content_coding.o: est_content_coding.c est_token.c
	gcc -c est_content_coding.c est_token.c
est_content_encoding.o: est_content_encoding.c est_content_coding.c
	gcc -c est_content_encoding.c est_content_coding.c
est_content_language.o: est_content_language.c est_language_tag.c
	gcc -c est_content_language.c est_language_tag.c
est_content_length.o: est_content_length.c est_digit.c
	gcc -c est_content_length.c est_digit.c
est_content_length_header.o: est_content_length_header.c est_content_length.c
	gcc -c est_content_length_header.c est_content_length.c
est_content_location.o: est_content_location.c est_partial_uri.c est_absolute_uri.c
	gcc -c est_content_location.c est_partial_uri.c est_absolute_uri.c
est_content_range.o: est_content_range.c est_byte_content_range.c est_other_content_range.c
	gcc -c est_content_range.c est_byte_content_range.c est_other_content_range.c
est_content_type.o: est_content_type.c est_media_type.c
	gcc -c est_content_type.c est_media_type.c
est_cookie_header.o: est_cookie_header.c est_cookie_string.c
	gcc -c est_cookie_header.c est_cookie_string.c
est_cookie_name.o: est_cookie_name.c est_token.c
	gcc -c est_cookie_name.c est_token.c
est_cookie_octet.o: est_cookie_octet.c
	gcc -c est_cookie_octet.c
est_cookie_pair.o: est_cookie_pair.c est_cookie_name.c est_cookie_value.c
	gcc -c est_cookie_pair.c est_cookie_name.c est_cookie_value.c
est_cookie_string.o: est_cookie_string.c est_cookie_pair.c
	gcc -c est_cookie_string.c est_cookie_pair.c
est_cookie_value.o: est_cookie_value.c est_cookie_octet.c
	gcc -c est_cookie_value.c est_cookie_octet.c
est_credentials.o: est_credentials.c est_challenge.c
	gcc -c est_credentials.c est_challenge.c
est_crlf.o: est_crlf.c
	gcc -c est_crlf.c
est_ctext.o: est_ctext.c est_obs_text.c
	gcc -c est_ctext.c est_obs_text.c
est_date.o: est_date.c est_http_date.c
	gcc -c est_date.c est_http_date.c
est_date1.o: est_date1.c est_day.c est_month.c est_year.c
	gcc -c est_date1.c est_day.c est_month.c est_year.c
est_date2.o: est_date2.c est_day.c est_month.c est_digit.c
	gcc -c est_date2.c est_day.c est_month.c est_digit.c
est_date3.o: est_date3.c est_month.c est_digit.c
	gcc -c est_date3.c est_month.c est_digit.c
est_date_header.o: est_date_header.c est_date.c
	gcc -c est_date_header.c est_date.c
est_day.o: est_day.c est_digit.c
	gcc -c est_day.c est_digit.c
est_day_name.o: est_day_name.c
	gcc -c est_day_name.c
est_day_name_l.o: est_day_name_l.c
	gcc -c est_day_name_l.c
est_dec_octet.o: est_dec_octet.c est_digit.c
	gcc -c est_dec_octet.c est_digit.c
est_delay_seconds.o: est_delay_seconds.c est_digit.c
	gcc -c est_delay_seconds.c est_digit.c
est_delta_seconds.o: est_delta_seconds.c est_digit.c
	gcc -c est_delta_seconds.c est_digit.c
est_digit.o: est_digit.c
	gcc -c est_digit.c
est_dquote.o: est_dquote.c
	gcc -c est_dquote.c
est_entity_tag.o: est_entity_tag.c est_weak.c est_opaque_tag.c
	gcc -c est_entity_tag.c est_weak.c est_opaque_tag.c
est_etag.o: est_entity_tag.c est_etag.c
	gcc -c est_entity_tag.c est_etag.c
est_etagc.o: est_etagc.c
	gcc -c est_etagc.c
est_expect.o: est_expect.c
	gcc -c est_expect.c
est_expect_header.o: est_expect_header.c est_expect.c
	gcc -c est_expect_header.c est_expect.c
est_expires.o: est_expires.c est_http_date.c
	gcc -c est_expires.c est_http_date.c
est_expires_header.o: est_expires_header.c est_expires.c
	gcc -c est_expires_header.c est_expires.c
est_extension.o: est_extension.c est_singleton.c est_alphanum.c
	gcc -c est_extension.c est_singleton.c est_alphanum.c
est_extension_pragma.o: est_extension_pragma.c est_cache_directive.c
	gcc -c est_extension_pragma.c est_cache_directive.c
est_extlang.o: est_extlang.c est_alpha.c
	gcc -c est_extlang.c est_alpha.c
est_field_content.o: est_field_content.c est_field_vchar.c
	gcc -c est_field_content.c est_field_vchar.c
est_field_name.o: est_field_name.c est_token.c
	gcc -c est_field_name.c est_token.c
est_field_value.o: est_field_value.c est_obs_text.c est_vchar.c
	gcc -c est_field_value.c est_obs_text.c est_vchar.c
est_field_vchar.o: est_field_vchar.c est_obs_text.c est_vchar.c
	gcc -c est_field_vchar.c est_obs_text.c est_vchar.c
est_first_byte_pos.o: est_first_byte_pos.c est_complete_length.c
	gcc -c est_first_byte_pos.c est_complete_length.c
est_fragment.o: est_fragment.c est_pchar.c
	gcc -c est_fragment.c est_pchar.c
est_gen_delims.o: est_gen_delims.c
	gcc -c est_gen_delims.c
est_gmt.o: est_gmt.c
	gcc -c est_gmt.c
est_grandfathered.o: est_grandfathered.c est_regular.c est_irregular.c
	gcc -c est_grandfathered.c est_regular.c est_irregular.c
est_h16.o: est_h16.c est_hexdig.c
	gcc -c est_h16.c est_hexdig.c
est_header_field.o: est_connection.c est_content_length.c est_trailer.c est_transfer_encoding.c est_upgrade.c est_via.c est_age.c est_expires.c est_date.c est_location.c est_retry_after.c est_vary.c est_warning.c est_cache_control.c est_expect.c est_host.c est_max_forwards.c est_pragma.c est_range.c est_te.c est_if_match.c est_if_none_match.c est_if_modified_since.c est_if_unmodified_since.c est_if_range.c est_accept.c est_accept_charset.c est_accept_encoding.c est_accept_language.c est_authorization.c est_proxy_authorization.c est_referer.c est_user_agent.c
	gcc -c est_connection.c est_content_length.c est_trailer.c est_transfer_encoding.c est_upgrade.c est_via.c est_age.c est_expires.c est_date.c est_location.c est_retry_after.c est_vary.c est_warning.c est_cache_control.c est_expect.c est_host.c est_max_forwards.c est_pragma.c est_range.c est_te.c est_if_match.c est_if_none_match.c est_if_modified_since.c est_if_unmodified_since.c est_if_range.c est_accept.c est_accept_charset.c est_accept_encoding.c est_accept_language.c est_authorization.c est_proxy_authorization.c est_referer.c est_user_agent.c
est_hexdig.o: est_hexdig.c est_digit.c
	gcc -c est_hexdig.c est_digit.c
est_hier_part.o: est_hier_part.c est_path_absolute.c est_path_rootless.c est_path_empty.c est_authority.c est_path_abempty.c
	gcc -c est_hier_part.c est_path_absolute.c est_path_rootless.c est_path_empty.c est_authority.c est_path_abempty.c
est_host.o: est_host.c est_ip_literal.c est_ipv4address.c est_reg_name.c
	gcc -c est_host.c est_ip_literal.c est_ipv4address.c est_reg_name.c
est_Host.o: est_Host.c est_port.c est_uri_host.c
	gcc -c est_Host.c est_port.c est_uri_host.c
est_host_header.o: est_host_header.c est_Host.c
	gcc -c est_host_header.c est_Host.c
est_hour.o: est_hour.c
	gcc -c est_hour.c
est_http_date.o: est_http_date.c est_imf_fixdate.c est_obs_date.c
	gcc -c est_http_date.c est_imf_fixdate.c est_obs_date.c
est_http_message.o: est_http_message.c est_header_field.c est_message_body.c est_start_line.c
	gcc -c est_http_message.c est_header_field.c est_message_body.c est_start_line.c
est_http_name.o: est_http_name.c
	gcc -c est_http_name.c
est_https_uri.o: est_https_uri.c est_authority.c est_fragment.c est_query.c est_path_abempty.c
	gcc -c est_https_uri.c est_authority.c est_fragment.c est_query.c est_path_abempty.c
est_http_uri.o: est_http_uri.c est_query.c est_fragment.c est_authority.c est_path_abempty.c
	gcc -c est_http_uri.c est_query.c est_fragment.c est_authority.c est_path_abempty.c
est_http_version.o: est_http_version.c est_http_name.c est_digit.c
	gcc -c est_http_version.c est_http_name.c est_digit.c
est_if_match.o: est_if_match.c est_entity_tag.c
	gcc -c est_if_match.c est_entity_tag.c
est_if_match_header.o: est_if_match_header.c est_if_match.c
	gcc -c est_if_match_header.c est_if_match.c
est_if_modified_since.o: est_if_modified_since.c est_http_date.c
	gcc -c est_if_modified_since.c est_http_date.c
est_if_modified_since_header.o: est_if_modified_since_header.c est_if_modified_since.c
	gcc -c est_if_modified_since_header.c est_if_modified_since.c
est_if_none_match.o: est_if_none_match.c est_entity_tag.c
	gcc -c est_if_none_match.c est_entity_tag.c
est_if_none_match_header.o: est_if_none_match_header.c est_if_none_match.c
	gcc -c est_if_none_match_header.c est_if_none_match.c
est_if_range.o: est_if_range.c est_entity_tag.c est_http_date.c
	gcc -c est_if_range.c est_entity_tag.c est_http_date.c
est_if_range_header.o: est_if_range_header.c est_if_range.c
	gcc -c est_if_range_header.c est_if_range.c
est_if_unmodified_since.o: est_if_unmodified_since.c est_http_date.c
	gcc -c est_if_unmodified_since.c est_http_date.c
est_if_unmodified_since_header.o: est_if_unmodified_since_header.c est_if_unmodified_since.c
	gcc -c est_if_unmodified_since_header.c est_if_unmodified_since.c
est_imf_fixdate.o: est_imf_fixdate.c est_date1.c est_time_of_day.c est_gmt.c
	gcc -c est_imf_fixdate.c est_date1.c est_time_of_day.c est_gmt.c
est_ip_literal.o: est_ip_literal.c est_ipv6address.c est_ipvfuture.c
	gcc -c est_ip_literal.c est_ipv6address.c est_ipvfuture.c
est_ipv4address.o: est_ipv4address.c est_dec_octet.c
	gcc -c est_ipv4address.c est_dec_octet.c
est_ipv6address.o: est_ipv6address.c est_ls32.c est_h16.c
	gcc -c est_ipv6address.c est_ls32.c est_h16.c
est_ipvfuture.o: est_ipvfuture.c est_sub_delims.c est_unreserved.c
	gcc -c est_ipvfuture.c est_sub_delims.c est_unreserved.c
est_irregular.o: est_irregular.c
	gcc -c est_irregular.c
est_langtag.o: est_langtag.c est_alpha.c est_region.c est_script.c est_language.c est_privateuse.c est_extension.c
	gcc -c est_langtag.c est_alpha.c est_region.c est_script.c est_language.c est_privateuse.c est_extension.c
est_language.o: est_language.c est_extlang.c
	gcc -c est_language.c est_extlang.c
est_language_range.o: est_language_range.c est_alpha.c
	gcc -c est_language_range.c est_alpha.c
est_language_tag.o: est_language_tag.c est_langtag.c est_privateuse.c est_grandfathered.c
	gcc -c est_language_tag.c est_langtag.c est_privateuse.c est_grandfathered.c
est_last_byte_pos.o: est_last_byte_pos.c est_complete_length.c
	gcc -c est_last_byte_pos.c est_complete_length.c
est_last_chunk.o: est_last_chunk.c est_chunk_ext.c
	gcc -c est_last_chunk.c est_chunk_ext.c
est_last_modified.o: est_last_modified.c est_http_date.c
	gcc -c est_last_modified.c est_http_date.c
est_location.o: est_location.c est_uri_reference.c
	gcc -c est_location.c est_uri_reference.c
est_location_header.o: est_location_header.c est_location.c
	gcc -c est_location_header.c est_location.c
est_ls32.o: est_ls32.c est_h16.c
	gcc -c est_ls32.c est_h16.c
est_max_forwards.o: est_max_forwards.c est_digit.c
	gcc -c est_max_forwards.c est_digit.c
est_max_forwards_header.o: est_max_forwards_header.c est_max_forwards.c
	gcc -c est_max_forwards_header.c est_max_forwards.c
est_media_range.o: est_media_range.c est_type.c est_subtype.c est_parameter.c
	gcc -c est_media_range.c est_type.c est_subtype.c est_parameter.c
est_media_type.o: est_media_type.c est_type.c est_subtype.c est_parameter.c
	gcc -c est_media_type.c est_type.c est_subtype.c est_parameter.c
est_message_body.o: est_message_body.c
	gcc -c est_message_body.c
est_method.o: est_token.c
	gcc -c est_token.c
est_minute.o: est_minute.c
	gcc -c est_minute.c
est_month.o: est_month.c
	gcc -c est_month.c
est_obs_date.o: est_obs_date.c est_rfc850_date.c est_asctime_date.c
	gcc -c est_obs_date.c est_rfc850_date.c est_asctime_date.c
est_obs_fold.o: est_obs_fold.c
	gcc -c est_obs_fold.c
est_obs_text.o: est_obs_text.c
	gcc -c est_obs_text.c
est_opaque_tag.o: est_opaque_tag.c est_etagc.c
	gcc -c est_opaque_tag.c est_etagc.c
est_origin_form.o: est_origin_form.c est_absolute_path.c est_query.c
	gcc -c est_origin_form.c est_absolute_path.c est_query.c
est_other_content_range.o: est_other_content_range.c est_other_range_unit.c est_other_range_resp.c
	gcc -c est_other_content_range.c est_other_range_unit.c est_other_range_resp.c
est_other_range_resp.o: est_other_range_resp.c est_char.c
	gcc -c est_other_range_resp.c est_char.c
est_other_range_set.o: est_other_range_set.c est_vchar.c
	gcc -c est_other_range_set.c est_vchar.c
est_other_ranges_specifier.o: est_other_ranges_specifier.c est_other_range_unit.c est_other_range_set.c
	gcc -c est_other_ranges_specifier.c est_other_range_unit.c est_other_range_set.c
est_other_range_unit.o: est_other_range_unit.c est_token.c
	gcc -c est_other_range_unit.c est_token.c
est_parameter.o: est_parameter.c est_token.c est_quoted_string.c
	gcc -c est_parameter.c est_token.c est_quoted_string.c
est_partial_uri.o: est_partial_uri.c est_relative_part.c est_query.c
	gcc -c est_partial_uri.c est_relative_part.c est_query.c
est_path.o: est_path.c est_path_abempty.c est_path_noscheme.c est_path_absolute.c est_path_empty.c est_path_rootless.c
	gcc -c est_path.c est_path_abempty.c est_path_noscheme.c est_path_absolute.c est_path_empty.c est_path_rootless.c
est_path_abempty.o: est_path_abempty.c est_segment.c
	gcc -c est_path_abempty.c est_segment.c
est_path_absolute.o: est_path_absolute.c est_segment.c est_segment_nz.c
	gcc -c est_path_absolute.c est_segment.c est_segment_nz.c
est_path_empty.o: est_path_empty.c
	gcc -c est_path_empty.c
est_path_noscheme.o: est_path_noscheme.c est_segment.c est_segment_nz_nc.c
	gcc -c est_path_noscheme.c est_segment.c est_segment_nz_nc.c
est_path_rootless.o: est_path_rootless.c est_segment.c est_segment_nz.c
	gcc -c est_path_rootless.c est_segment.c est_segment_nz.c
est_pchar.o: est_pchar.c est_unreserved.c est_sub_delims.c est_pct_encoded.c
	gcc -c est_pchar.c est_unreserved.c est_sub_delims.c est_pct_encoded.c
est_pct_encoded.o: est_pct_encoded.c est_hexdig.c
	gcc -c est_pct_encoded.c est_hexdig.c
est_port.o: est_port.c est_digit.c
	gcc -c est_port.c est_digit.c
est_pragma.o: est_pragma.c est_pragma_directive.c
	gcc -c est_pragma.c est_pragma_directive.c
est_pragma_directive.o: est_pragma_directive.c
	gcc -c est_pragma_directive.c
est_pragma_header.o: est_pragma_header.c
	gcc -c est_pragma_header.c
est_privateuse.o: est_privateuse.c est_alphanum.c
	gcc -c est_privateuse.c est_alphanum.c
est_product.o: est_product.c est_product_version.c est_token.c
	gcc -c est_product.c est_product_version.c est_token.c
est_product_version.o: est_product_version.c est_token.c
	gcc -c est_product_version.c est_token.c
est_protocol.o: est_protocol.c est_protocol_name.c est_protocol_version.c
	gcc -c est_protocol.c est_protocol_name.c est_protocol_version.c
est_protocol_name.o: est_protocol_name.c est_token.c
	gcc -c est_protocol_name.c est_token.c
est_protocol_version.o: est_protocol_version.c est_token.c
	gcc -c est_protocol_version.c est_token.c
est_proxy_authenticate.o: est_proxy_authenticate.c est_challenge.c
	gcc -c est_proxy_authenticate.c est_challenge.c
est_proxy_authorization.o: est_proxy_authorization.c est_credentials.c
	gcc -c est_proxy_authorization.c est_credentials.c
est_proxy_authorization_header.o: est_proxy_authorization_header.c est_proxy_authorization.c
	gcc -c est_proxy_authorization_header.c est_proxy_authorization.c
est_pseudonym.o: est_pseudonym.c est_token.c
	gcc -c est_pseudonym.c est_token.c
est_qdtext.o: est_qdtext.c est_token.c
	gcc -c est_qdtext.c est_token.c
est_query.o: est_query.c est_pchar.c
	gcc -c est_query.c est_pchar.c
est_quoted_pair.o: est_quoted_pair.c est_vchar.c est_obs_text.c
	gcc -c est_quoted_pair.c est_vchar.c est_obs_text.c
est_quoted_string.o: est_quoted_string.c est_qdtext.c est_quoted_pair.c
	gcc -c est_quoted_string.c est_qdtext.c est_quoted_pair.c
est_qvalue.o: est_qvalue.c est_digit.c
	gcc -c est_qvalue.c est_digit.c
est_range.o: est_range.c est_byte_ranges_specifier.c est_other_ranges_specifier.c
	gcc -c est_range.c est_byte_ranges_specifier.c est_other_ranges_specifier.c
est_range_header.o: est_range_header.c est_range.c
	gcc -c est_range_header.c est_range.c
est_range_unit.o: est_range_unit.c est_bytes_unit.c est_other_range_unit.c
	gcc -c est_range_unit.c est_bytes_unit.c est_other_range_unit.c
est_rank.o: est_rank.c est_digit.c
	gcc -c est_rank.c est_digit.c
est_reason_phrase.o: est_reason_phrase.c est_vchar.c est_obs_text.c
	gcc -c est_reason_phrase.c est_vchar.c est_obs_text.c
est_received_by.o: est_received_by.c est_uri_host.c est_port.c est_pseudonym.c
	gcc -c est_received_by.c est_uri_host.c est_port.c est_pseudonym.c
est_received_protocol.o: est_received_protocol.c est_protocol_name.c est_protocol_version.c
	gcc -c est_received_protocol.c est_protocol_name.c est_protocol_version.c
est_referer.o: est_referer.c est_absolute_uri.c est_partial_uri.c
	gcc -c est_referer.c est_absolute_uri.c est_partial_uri.c
est_referer_header.o: est_referer_header.c est_referer.c
	gcc -c est_referer_header.c est_referer.c
est_region.o: est_region.c est_alpha.c est_digit.c
	gcc -c est_region.c est_alpha.c est_digit.c
est_reg_name.o: est_reg_name.c est_sub_delims.c est_unreserved.c est_pct_encoded.c
	gcc -c est_reg_name.c est_sub_delims.c est_unreserved.c est_pct_encoded.c
est_regular.o: est_regular.c
	gcc -c est_regular.c
est_relative_part.o: est_relative_part.c est_path_empty.c est_path_absolute.c est_path_noscheme.c est_authority.c est_path_abempty.c
	gcc -c est_relative_part.c est_path_empty.c est_path_absolute.c est_path_noscheme.c est_authority.c est_path_abempty.c
est_relative_ref.o: est_relative_ref.c est_relative_part.c est_fragment.c est_query.c
	gcc -c est_relative_ref.c est_relative_part.c est_fragment.c est_query.c
est_request_line.o: est_request_line.c est_method.c est_request_target.c est_http_version.c
	gcc -c est_request_line.c est_method.c est_request_target.c est_http_version.c
est_request_target.o: est_request_target.c est_origin_form.c est_absolute_form.c est_authority_form.c est_asterisk_form.c
	gcc -c est_request_target.c est_origin_form.c est_absolute_form.c est_authority_form.c est_asterisk_form.c
est_reserved.o: est_reserved.c est_gen_delims.c est_sub_delims.c
	gcc -c est_reserved.c est_gen_delims.c est_sub_delims.c
est_retry_after.o: est_retry_after.c est_http_date.c est_delay_seconds.c
	gcc -c est_retry_after.c est_http_date.c est_delay_seconds.c
est_retry_after_header.o: est_retry_after_header.c est_retry_after.c
	gcc -c est_retry_after_header.c est_retry_after.c
est_rfc850_date.o: est_rfc850_date.c est_day_name_l.c est_date2.c est_time_of_day.c est_gmt.c
	gcc -c est_rfc850_date.c est_day_name_l.c est_date2.c est_time_of_day.c est_gmt.c
est_scheme.o: est_scheme.c est_alpha.c est_digit.c
	gcc -c est_scheme.c est_alpha.c est_digit.c
est_script.o: est_script.c est_alpha.c
	gcc -c est_script.c est_alpha.c
est_second.o: est_second.c
	gcc -c est_second.c
est_segment.o: est_segment.c est_pchar.c
	gcc -c est_segment.c est_pchar.c
est_segment_nz.o: est_segment_nz.c est_pchar.c
	gcc -c est_segment_nz.c est_pchar.c
est_segment_nz_nc.o: est_segment_nz_nc.c est_sub_delims.c est_unreserved.c est_pct_encoded.c
	gcc -c est_segment_nz_nc.c est_sub_delims.c est_unreserved.c est_pct_encoded.c
est_server.o: est_server.c est_product.c est_subtype.c est_comment.c
	gcc -c est_server.c est_product.c est_subtype.c est_comment.c
est_singleton.o: est_singleton.c est_digit.c
	gcc -c est_singleton.c est_digit.c
est_start_line.o: est_start_line.c est_request_line.c est_status_line.c
	gcc -c est_start_line.c est_request_line.c est_status_line.c
est_status_code.o: est_status_code.c
	gcc -c est_status_code.c
est_status_line.o: est_status_line.c est_http_version.c est_status_code.c est_reason_phrase.c
	gcc -c est_status_line.c est_http_version.c est_status_code.c est_reason_phrase.c
est_sub_delims.o: est_sub_delims.c
	gcc -c est_sub_delims.c
est_subtype.o: est_subtype.c est_token.c
	gcc -c est_subtype.c est_token.c
est_suffix_byte_range_spec.o: est_suffix_byte_range_spec.c est_suffix_length.c
	gcc -c est_suffix_byte_range_spec.c est_suffix_length.c
est_suffix_length.o: est_suffix_length.c est_digit.c
	gcc -c est_suffix_length.c est_digit.c
est_tchar.o: est_tchar.c est_digit.c est_alpha.c
	gcc -c est_tchar.c est_digit.c est_alpha.c
est_t_codings.o: est_t_codings.c est_t_ranking.c
	gcc -c est_t_codings.c est_t_ranking.c
est_te.o: est_te.c est_t_codings.c
	gcc -c est_te.c est_t_codings.c
est_te_header.o: est_te_header.c est_te.c
	gcc -c est_te_header.c est_te.c
est_time_of_day.o: est_time_of_day.c est_hour.c est_minute.c est_second.c
	gcc -c est_time_of_day.c est_hour.c est_minute.c est_second.c
est_token.o: est_token.c est_tchar.c
	gcc -c est_token.c est_tchar.c
est_token68.o: est_token68.c est_alpha.c est_digit.c
	gcc -c est_token68.c est_alpha.c est_digit.c
est_trailer.o: est_trailer.c est_field_name.c
	gcc -c est_trailer.c est_field_name.c
est_trailer_header.o: est_trailer_header.c est_trailer.c
	gcc -c est_trailer_header.c est_trailer.c
est_trailer_part.o: est_trailer_part.c est_header_field.c
	gcc -c est_trailer_part.c est_header_field.c
est_t_ranking.o: est_t_ranking.c est_rank.c
	gcc -c est_t_ranking.c est_rank.c
est_transfer_coding.o: est_transfer_coding.c est_transfer_extension.c
	gcc -c est_transfer_coding.c est_transfer_extension.c
est_transfer_encoding.o: est_transfer_encoding.c
	gcc -o est_transfer_encoding.o -c est_transfer_encoding.c -W -Wall -ansi -pedantic
est_transfer_encoding_header.o: est_transfer_encoding_header.c est_transfer_encoding.c
	gcc -c est_transfer_encoding_header.c est_transfer_encoding.c
est_transfer_extension.o: est_transfer_extension.c est_token.c est_transfer_parameter.c
	gcc -c est_transfer_extension.c est_token.c est_transfer_parameter.c
est_transfer_parameter.o: est_transfer_parameter.c est_token.c est_quoted_string.c
	gcc -c est_transfer_parameter.c est_token.c est_quoted_string.c
est_type.o: est_type.c est_token.c
	gcc -c est_type.c est_token.c
est_unreserved.o: est_unreserved.c est_alpha.c est_digit.c
	gcc -c est_unreserved.c est_alpha.c est_digit.c
est_unsatisfied_range.o: est_unsatisfied_range.c est_complete_length.c
	gcc -c est_unsatisfied_range.c est_complete_length.c
est_upgrade.o: est_upgrade.c est_protocol.c
	gcc -c est_upgrade.c est_protocol.c
est_upgrade_header.o: est_upgrade_header.c est_upgrade.c
	gcc -c est_upgrade_header.c est_upgrade.c
est_uri.o: est_uri.c est_scheme.c est_query.c est_hier_part.c est_fragment.c
	gcc -c est_uri.c est_scheme.c est_query.c est_hier_part.c est_fragment.c
est_uri_host.o: est_uri_host.c est_host.c
	gcc -c est_uri_host.c est_host.c
est_uri_reference.o: est_uri_reference.c est_uri.c est_relative_ref.c
	gcc -c est_uri_reference.c est_uri.c est_relative_ref.c
est_user_agent.o: est_user_agent.c est_product.c  est_comment.c
	gcc -c est_user_agent.c est_product.c  est_comment.c
est_user_agent_header.o: est_user_agent_header.c est_user_agent.c
	gcc -c est_user_agent_header.c est_user_agent.c
est_userinfo.o: est_userinfo.c est_pct_encoded.c est_unreserved.c  est_sub_delims.c
	gcc -c est_userinfo.c est_pct_encoded.c est_unreserved.c  est_sub_delims.c
est_variant.o: est_variant.c est_digit.c est_alphanum.c
	gcc -c est_variant.c est_digit.c est_alphanum.c
est_vary.o: est_vary.c est_field_name.c
	gcc -c est_vary.c est_field_name.c
est_vary_header.o: est_vary_header.c est_vary.c
	gcc -c est_vary_header.c est_vary.c
est_vchar.o: est_vchar.c
	gcc -c est_vchar.c
est_via.o: est_via.c est_received_protocol.c est_received_by.c est_comment.c
	gcc -c est_via.c est_received_protocol.c est_received_by.c est_comment.c
est_via_header.o: est_via_header.c est_via.c
	gcc -c est_via_header.c est_via.c
est_warn_agent.o: est_warn_agent.c est_host.c est_pseudonym.c
	gcc -c est_warn_agent.c est_host.c est_pseudonym.c
est_warn_code.o: est_warn_code.c est_digit.c
	gcc -c est_warn_code.c est_digit.c
est_warn_date.o: est_warn_date.c est_http_date.c
	gcc -c est_warn_date.c est_http_date.c
est_warning.o: est_warning.c est_warning_value.c
	gcc -c est_warning.c est_warning_value.c
est_warning_header.o: est_warning_header.c est_warning.c
	gcc -c est_warning_header.c est_warning.c
ajoutContentLength.o: ajoutContentLength.c
	gcc -c ajoutContentLength.c
ajoutContentType.o: ajoutContentType.c
	gcc -c ajoutContentType.c
est_warn_text.o: est_warn_text.c est_quoted_string.c
	gcc -c est_warn_text.c est_quoted_string.c
est_warning_value.o: est_warning_value.c est_warn_code.c est_warn_agent.c est_warn_date.c est_warn_text.c
	gcc -c est_warning_value.c est_warn_code.c est_warn_agent.c est_warn_date.c est_warn_text.c
est_weak.o: est_weak.c
	gcc -c est_weak.c
test.o: test.c
	gcc -c test.c
est_weight.o: est_weight.c est_qvalue.c
	gcc -c est_weight.c est_qvalue.c
est_year.o: est_year.c est_digit.c
	gcc -c est_year.c est_digit.c
est_www_authenticate.o: est_www_authenticate.c est_challenge.c
	gcc -c est_www_authenticate.c est_challenge.c
main.o: main.c config_init.c parseur.c semantique.c norm_URL.c remplissageStruct.c fonctionx.c ajout_fichier.c recup_fichier.c suppr_fichier.c ajoutDate.c ajoutServeur.c ajoutContentLength.c ajoutMessageCode.c ajoutContentType.c create_res.c test.c librequest.so
	gcc -c main.c config_init.c parseur.c semantique.c norm_URL.c remplissageStruct.c fonctionx.c ajout_fichier.c test.c recup_fichier.c suppr_fichier.c ajoutDate.c ajoutServeur.c ajoutContentLength.c ajoutContentType.c ajoutMessageCode.c create_res.c -L . -librequest librequest.so
clean:
	rm *.o
